#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
int n, m, maxn1, maxn2, x, y;

vector <vector <int> > g, new_graph;
pair <int, int> pd[10005];
map <pair <int, int>, int> mp;
int used[105], us[105], ans = 1000000, index = -1, dist, dist_in = -1, st;
vector <int> res, edges;

int dfs(int s, int k) {
    if(k > dist) {
        dist = k;
        dist_in = s;
    }
    us[s] = 1;
    for(int i = 0; i < new_graph[s].size(); ++i) {
        int to = new_graph[s][i];
        if(!us[to]) dfs(to, k + 1);
    }
}
int diameter(int in) {
    memset(us, 0, sizeof us);
    dist = 0, dist_in = -1;
    dfs(in, 0);
    dist = 0;
    memset(us, 0, sizeof us);
    dfs(dist_in, 0);
    if(dist < ans) {
        ans = dist;
        res.clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < new_graph[i].size(); ++j) {
                if(new_graph[i][j] <= i) continue;
                res.push_back(mp[{i, new_graph[i][j]}]);
            }
        }
    }
    return dist;
}

int bfs(int s, queue <int> q, int c) {
    new_graph.clear(); new_graph.resize(n + 1);
    if(c == 1) {
        new_graph[pd[s].first].push_back(pd[s].second);
        new_graph[pd[s].second].push_back(pd[s].first);
    }
    while(!q.empty()) {
        int top = q.front(); q.pop();
        for(int j = 0; j < g[top].size(); ++j) {
            int to = g[top][j];
            if(!used[to]) {
                q.push(to);
                used[to] = 1;
                new_graph[top].push_back(to), new_graph[to].push_back(top);
            }
        }
    }
    if(c == 1) return diameter(pd[s].first);
    return diameter(s);
}
int main() {
    cin >> n >> m;
    g.resize(n + 2); new_graph.resize(n + 2);
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
        pd[i] = {x,y}, mp[{x,y}] = mp[{y,x}] = i;
    }
    for(int i = 1; i <= n; ++i) {
        memset(used, 0, sizeof used);
        queue<int> q; q.push(i); used[i] = 1;
        int x = bfs(i, q, 0);
    }

    for(int i = 0; i < m; ++i) {
        memset(used,0,sizeof used);
        queue<int> q;
        q.push(pd[i].first);
        q.push(pd[i].second);
        used[pd[i].first] = used[pd[i].second] = 1;
        int x = bfs(i, q, 1);
        if(x < ans) {
            ans = x;
        }
    }

    for(int i = 0; i < res.size(); ++i) {
        cout << pd[res[i]].first << " " << pd[res[i]].second << endl;
    }
}

