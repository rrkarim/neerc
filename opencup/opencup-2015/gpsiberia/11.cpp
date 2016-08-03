/**
*/
#include <bits/stdc++.h>
#define MAXN 211005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n, x, y, xt, yt, k, ks, m, t, as[MAXN + 2];
vector <int> go[MAXN + 2];
void dfs(int v) {
    ks += 1;
    as[v] = 1;
    for(int i = 0; i < go[v].size(); ++i) {
        int to = go[v][i];
        if(!as[to]) dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> m;
    for(int i = 0; i < k; ++i) {
        cin >> t;
        as[t] = 1;
    }
    for(int i = 0; i < m; ++i) {
        cin >> xt >> yt;
        go[yt].push_back(xt);
        if(as[yt] == 1) {
            ks = 0;
            dfs(yt);
            k += ks - 1;
        }
        cout << k << endl;
    }

}
