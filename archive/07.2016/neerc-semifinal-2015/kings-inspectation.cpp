/**
    Rasul Kerimov (CoderINusE)
    King's Inspectation
    Not complete (TL 108)
*/
#include <bits/stdc++.h>
#define MAXN 120005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;
vector<int> g[MAXN + 2], go[MAXN + 2];
int n, m, d_i[MAXN + 2], d_o[MAXN + 2], special[MAXN + 2];
int path[MAXN + 2], used[MAXN + 2], u, v;
void imp() {
    cout << "There is no route, Karl!" << endl;
    exit(0);
}

void dfs(int v, int w) {
    if(w == n) {
        for(int i = 0; i < n; ++i)
            printf("%d ", path[i] + 1);;
        printf("1\n");
        exit(0);
    }
    if (!v && w) return;
    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(!used[to]) {
            used[to] = 1;
            path[w + 1] = to;
            dfs(to, w + 1);
            used[to] = 0;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        u -= 1; v -= 1;
        g[u].push_back(v);
        go[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) {
        if(g[i].empty() || go[i].empty()) imp();
    }



    //tourist simple idea
    for(int i = 0; i < n; ++i) {
        if(g[i].size() != 1) continue;
        int to = g[i][0];
        for(int j = 0; j < go[to].size(); ++j) {
            int z = go[to][j];
            if(z != i) {
                g[z].erase(find(g[z].begin(), g[z].end(), to));
            }
        }
        go[to].resize(1);
        go[to][0] = i;
    }


    path[0] = 0;
    dfs(0, 0);
    imp();

}
