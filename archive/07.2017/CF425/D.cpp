//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 100005

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int , int > ii ;

int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
int timer, deep[MAXN + 2];
vector < vector<int> > up;

void dfs (int v, int p = 0, int dp = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	deep[v] = dp;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v, dp + 1);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}
int p_, q, dx[5];

int solve() {
    int maxn = INT_MIN;
    sort(dx, dx + 3);
    do {
        // 1, 3, 0
        int f = dx[0], s = dx[1], t = dx[2];
        int fs = lca(f, s), ft = lca(f, t), st = lca(s, t);

        if(fs == ft) maxn = max(maxn, abs(deep[st] - deep[fs]) + abs(deep[fs] - deep[f]) + 1 );
        if(lca(fs, ft) == ft) maxn = max(maxn, abs(deep[fs] - deep[f]) + 1);
        else maxn = max(maxn, abs(deep[ft] - deep[f]) + 1);
    }
    while(next_permutation(dx, dx + 3));
    return maxn;
}

int main() {
    cin >> n >> q;
    g.resize(n + 2);
    for(int i = 1; i <= n - 1; ++i) {
        cin >> p_;
        g[p_-1].push_back(i);
        g[i].push_back(p_-1);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0);

    for(int i = 0; i < q; ++i) {
        cin >> dx[0] >> dx[1] >> dx[2];
        dx[0] -= 1, dx[1] -= 1, dx[2] -= 1;
        cout << solve() << endl;
    }

}