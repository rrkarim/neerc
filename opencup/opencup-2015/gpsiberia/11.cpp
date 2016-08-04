/**
*/
#include <bits/stdc++.h>
#define MAXN 111005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n, x, y, xt, yt, k, ks, m, t, as[MAXN + 2];
vector <vector<int> > go;
map <pair <int, int>, int > M;
void dfs(const int& v) {
    x += 1;
    ks += 1;
    as[v] = 1;
    for(int i = 0; i < go[v].size(); ++i) {
        int to = go[v][i];
        if(as[to] == 0) dfs(to);
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &m);
    go.resize(n + 2);
    for(int i = 0; i < k; ++i) {
        scanf("%d", &t);
        as[t] = 1;
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &xt, &yt);
        if(!M[{yt, xt}]) {
            go[yt].push_back(xt);
            M[{yt, xt}] = 1;
        }
        if(as[yt] == 1) {
            ks = 0;
            dfs(yt);
            k += ks - 1;
        }
        printf("%d\n", k);
    }
}
