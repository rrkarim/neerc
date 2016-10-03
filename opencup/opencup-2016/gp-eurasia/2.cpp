#include <bits/stdc++.h>
#include <string>
#define MAXN 100005
using namespace std;
typedef unsigned long long ll;
ll a[MAXN + 2];
vector < vector<int> > g;
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end, n;
map<pair<int,int>, int> u;
bool dfs (int v) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0) {
			p[to] = v;
			if (dfs (to))  return true;
		}
		else if (cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}
int main() {
    ios_base::sync_with_stdio(0);
	int n, m, x, y; cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        if(u[{x-1,y-1}] == 1) continue;
        g[x-1].push_back(y-1);
        u[{x-1,y-1}] = 1;

	}
	if(n == 1) {
        cout << -1 << endl;
        return 0;
	}
	p.assign (n, -1);
	cl.assign (n, 0);
	cycle_st = -1;
	for (int i=0; i<n; ++i)
		if (dfs (i))
			break;

	if (cycle_st == -1) {
        if(m == 0) cout << 2 << endl;
        else cout << 1 << endl;
	}
	else {
        cout << 0 << endl;
	}
}
