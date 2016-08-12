/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, k, color[150], t, used[150], index = 0;
char c;
vector <int> g[150];
void dfs(int v, int index) {
    used[v] = 1;
    for(int i = 0; i < index; ++i) printf(" ");
    if(v == 0) printf("%c project\n", (color[v] == 2 ? ' ' : (color[v] == 1 ? '+' : '-')) );
    else printf("%c object%d\n", (color[v] == 2 ? ' ' : (color[v] == 1 ? '+' : '-')), v );
    if(color[v] == 1 || color[v] == 2) return;

    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(!used[ to ]) {
            dfs(g[v][i], index + 2);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n + 1; ++i) {
        scanf(" %c%d", &c, &k);
        color[i] = (c == '+');
        if(!k) color[i] = 2;
        for(int j = 0; j < k; ++j) {
            scanf("%d", &t);
            g[i].push_back(t);
            g[t].push_back(i);
        }
    }
    dfs(0, 0);
}
