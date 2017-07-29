/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 1000005

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

/*
void input() {

    cin >> n >> k >> b;
    for(int i = 0; i < n; ++i) {
        cin >> a_ >> b_;
        d[i] = {a_, b_};
    }
    sort(d, d + n, cmp);
    for(int i = 0; i < n; ++i) {
        if(d[i].first == 1) {
            ;d1[]
        }
        else {

        }
    }

}
*/
int n, q, x, y, last = 0, temp_, f = 0, dp[MAXN + 2], q_[MAXN + 2], dfs_[MAXN + 2], tran[MAXN+2], gl = INT_MAX;
vector <vector <int> > g;

void dfs(int v, int deep, int minn = INT_MAX, int p = -1) {
    dp[v] = deep;
    minn = min(minn, v);
    dfs_[v] = minn, tran[v] = p;

    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to == p) continue;
        dfs(to, deep + 1, minn, v);
    }
}

void add_black(int v, int minn) {
    if(q_[v] != INT_MAX) return;
    minn = min(minn, v);
    q_[v] = min(minn, q_[v]);
    gl = min(gl, q_[v]);
    add_black(tran[v], minn);
}

int main() {
    scanf("%d%d", &n, &q);
    g.resize(n + 1);
    for(int i = 0; i < MAXN; ++i) q_[i] = INT_MAX;
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    while(q-- > 0) {
        scanf("%d%d", &x, &y); temp_ = (y + last) % n + 1;
        if(x == 1) {
            if(f == 0) {
                q_[temp_] = temp_;
                gl = temp_;
                dfs(temp_, 1);
            }
            else if(q_[temp_] == INT_MAX) add_black(temp_, temp_);
            f = 1;
        }
        else {
            last = min(dfs_[temp_], gl);
            printf("%d\n", last);
        }
    }
}