#include <bits/stdc++.h>
#define INF 100000000000005
#define MAXN 2000
#define mod 1000000007
#pragma comment(lib, "user32")

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

char mp[2005][2005];
int used[2005][2005], k = 0;

vector <int> re;
int set_rows[555][2005];
int set_columns[555][2005];
int set_size[555];

int tl = 0;
int n, m;
string temp;
vector <string> st;

int vi_r[2005][2005], vi_c[2005][2005];
int vi_r_suf[2005][2005], vi_c_suf[2005][2005];


void dfs(int v, int u) {
        if(v < 0 || v >= n) return;
        if(u < 0 || u >= m) return;

        if(used[v][u]) return;
        k += 1;

        set_rows[tl][v] = 1;
        set_columns[tl][u] = 1;
        set_size[tl] += 1;

        used[v][u] = 1;

        if(u < m - 1) {
            if(vi_r_suf[v][u + 1] != -1) {
                int to = vi_r_suf[v][u + 1];
                if(!used[v][to] && mp[v][to] == '+') {
                    dfs(v, to);
                }
            }
        }
        if(u > 0) {
            if(vi_r[v][u - 1] != -1) {
                int to = vi_r[v][u - 1];
                if(!used[v][to] && mp[v][to] == '+') {
                    dfs(v, to);
                }
            }
        }

        if(v > 0) {
            if(vi_c[u][v-1] != -1) {
                int to = vi_c[u][v - 1];
                if(!used[to][u] && mp[to][u] == '+') {
                    dfs(to, u);
                }
            }
        }
        if(v < n-1) {
            if(vi_c_suf[u][v+1] != -1) {
                int to = vi_c_suf[u][v + 1];
                if(!used[to][u] && mp[to][u] == '+') {
                    dfs(to, u);
                }
            }
        }




        return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int fo = 0, fi = 0;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        st.push_back(temp);
        for(int j = 0; j < temp.size(); ++j) {
            mp[i][j] = temp[j];
            if(temp[j] == '.') fo = 1;
            if(temp[j] == '+') fi = 1;

            if(temp[j] == '+') {
                vi_r[i][j] = j;
                vi_c[j][i] = i;
            }
            else {
                if(j == 0) vi_r[i][j] = -1;
                else vi_r[i][j] = vi_r[i][j - 1];

                if(i == 0) vi_c[j][i] = -1;
                else vi_c[j][i] = vi_c[j][i - 1];

            }

        }
    }


    for(int i = n - 1; i >= 0; --i) {
        for(int j = m - 1; j >= 0; --j) {
            if(st[i][j] == '+') {
                vi_c_suf[j][i] = i;
                vi_r_suf[i][j] = j;
            }
            else {

                if(j == m - 1) vi_r_suf[i][j] = -1;
                else vi_r_suf[i][j] = vi_r_suf[i][j + 1];

                if(i == n - 1) {
                    vi_c_suf[j][i] = -1;
                }
                else {
                    vi_c_suf[j][i] = vi_c_suf[j][i+1];
                }
            }
        }
    }

    if(fo == 0 || fi == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!used[i][j] && mp[i][j] == '+') {
                k = 0;
                dfs(i, j);

                tl += 1;
            }
        }
    }

    if(tl == 1) {
        cout << set_size[0] << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!used[i][j] && mp[i][j] == '.' && max(set_rows[0][i], set_columns[0][j]) >= 1) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }
    else {
        int maxn1 = 0, maxn2 = 0;
        int index1 = -1, index2 = -1;
        for(int i = 0; i < tl; ++i) {
            if(set_size[i] > maxn1) {
                maxn2 = maxn1;
                maxn1 = set_size[i];
                index2 = index1;
                index1 = i;
            }
            else if(set_size[i] > maxn2) {
                maxn2 = set_size[i];
                index2 = i;
            }
        }

        cout << maxn1 + maxn2 << endl;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if( !used[i][j] && mp[i][j] == '.' ) {

                    if(max(set_rows[index1][i], set_columns[index1][j]) + max(set_rows[index2][i], set_columns[index2][j]) >= 2) {
                        cout << i + 1 << " " << j + 1 << endl;
                        return 0;
                    }

                }
            }
        }
    }



}
