#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 2005
#define INF 10000000000000
using namespace std;

typedef long long ll;

struct p {
    int x, y, dist;
    p() {}
    p(int x, int y) : x(x), y(y) {}
    p(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};
int n, m;
char c[105], ms[105][105];

int dis_h[105][105];
p st, en, hl;
int xs[5] = {1, -1, 0, 0};
int ys[5] = {0, 0, 1, -1};

void bfs1() {
    queue <p> q;
    q.push({hl.x, hl.y, 0});
    int used[105][105];
    memset(used,0,sizeof used);
    for(int i = 0; i < 102; ++i) for(int j = 0; j < 102; ++j) dis_h[i][j] = -1;
    dis_h[hl.x][hl.y] = 0;
    while(!q.empty()) {
        p top = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int tox = top.x + xs[i];
            int toy = top.y + ys[i];
            if(tox < 0 || tox >= n || toy < 0 || toy >= m || used[tox][toy] || ms[tox][toy] == '#') continue;
            int new_dist = top.dist + 1;
            dis_h[tox][toy] = new_dist;
            q.push({tox, toy, new_dist});
            used[tox][toy] = 1;
        }

    }
}
bool bfs() {
    queue <p> q;
    q.push({st.x, st.y, 0});
    int used[105][105];
    memset(used,0,sizeof used);
    while(!q.empty()) {

        p top = q.front();
        q.pop();
        if(top.x == en.x && top.y == en.y) {
            return 1;
        }
        for(int i = 0; i < 4; ++i) {
            int tox = top.x + xs[i];
            int toy = top.y + ys[i];
            if(tox < 0 || tox >= n || toy < 0 || toy >= m) continue;
            if( ms[tox][toy] == '#' || used[tox][toy]) continue;
            int new_dist = top.dist + 1;
            if(dis_h[tox][toy] != -1) {
                if(dis_h[tox][toy] <= new_dist) continue;
            }
            q.push({tox, toy, new_dist});
            used[tox][toy] = 1;
        }
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0);
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; ++i) {
            scanf("%s", &c);
            for(int j = 0; j < strlen(c); ++j) {
                if(c[j] == 'S') st = {i, j};
                else if(c[j] == 'X') en = {i, j};
                else if(c[j] == '*') hl = {i, j};
                ms[i][j] = c[j];
            }
        }
        bfs1();
        if(bfs()) cout << "yes" << endl;
        else cout << "no" << endl;

    }
}