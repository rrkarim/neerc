/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
string s, c;
int n;

map <string, pair<int,int> > M;
int si = 0;

vector <pair <int, int> > vi;
int indexes[MAXN + 2];

void run(int n) {
    if(n == -1) return;
    run(indexes[n]);
    printf("%d ", n + 1);
}
int main() {
    //32
    ios_base::sync_with_stdio(0);
    //freopen("join.in", "r", stdin);
    //freopen("join.out", "w", stdout);
    int n, ans = 0, flags = 0, ind = -1; cin >> n;
    cin.ignore(256, '\n');
    for(int i = 0; i < n; ++i) {
        getline(cin, s); s += " ";
        string curr;
        int j = 0;
        for(j = 1; j < s.length(); ++j) {
            if(s[j] == ':') break;
            curr += s[j];
        }

        int maxn = 1, flag = 0, index = -1;
        string temp;
        for(j; j < s.length(); ++j) {

            if(s[j] == ' ' || s[j] == ':' ) {
                if(flag == 1) {
                    if(temp != curr) {
                        if(maxn < M[temp].first + 1) {
                            maxn = M[temp].first + 1;
                            index = M[temp].second;
                        }
                    }
                    temp = "";
                    flag = 0;
                    continue;
                }
            }

            if(flag == 1) {
                temp += s[j];
                continue;
            }

            if(s[j] == '@') {
                flag = 1;
            }
        }

        int t = M[curr].first;

        if(maxn > t) {
            M[curr] = {maxn, i};
            indexes[i] = index;
            t = maxn;
            index = i;
        }

        if(t > ans) {
            ans = t;
            ind = index;
        }
    }
    cout << ans << endl;
    run(ind);
    if(ans) printf("\n");
}
