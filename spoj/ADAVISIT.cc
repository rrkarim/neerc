#include <bits/stdc++.h>
#define INF 100000000000005
#define MAXN 400005
#define mod 1000000007
#pragma comment(lib, "user32")
 
using namespace std;
 
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
 
typedef vector < vector<int> > graph;
typedef vector<int>::const_iterator const_graph_iter;
 
 
vector<int> lca_h, lca_dfs_list, lca_first, lca_tree;
vector<char> lca_dfs_used;
int ans[MAXN + 2], parent[MAXN + 2];
 
void lca_dfs (const graph & g, int v, int h, int p) {
	lca_dfs_used[v] = true;
	lca_h[v] = h;
	lca_dfs_list.push_back (v);
	parent[v] = p;
	for(int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!lca_dfs_used[to]) {
			lca_dfs (g, to, h+1, v);
			lca_dfs_list.push_back (v);
		}
	}
}
 
void lca_build_tree (int i, int l, int r) {
	if (l == r)
		lca_tree[i] = lca_dfs_list[l];
	else {
		int m = (l + r) >> 1;
		lca_build_tree (i+i, l, m);
		lca_build_tree (i+i+1, m+1, r);
		if (lca_h[lca_tree[i+i]] < lca_h[lca_tree[i+i+1]])
			lca_tree[i] = lca_tree[i+i];
		else
			lca_tree[i] = lca_tree[i+i+1];
	}
}
 
void lca_prepare (const graph & g, int root) {
	int n = (int) g.size();
	lca_h.resize (n);
	lca_dfs_list.reserve (n*2);
	lca_dfs_used.assign (n, 0);
 
	lca_dfs (g, root, 1, -1);
 
	int m = (int) lca_dfs_list.size();
	lca_tree.assign (lca_dfs_list.size() * 4 + 1, -1);
	lca_build_tree (1, 0, m-1);
 
	lca_first.assign (n, -1);
	for (int i = 0; i < m; ++i)
	{
		int v = lca_dfs_list[i];
		if (lca_first[v] == -1)
			lca_first[v] = i;
	}
}
 
int lca_tree_min (int i, int sl, int sr, int l, int r) {
	if (sl == l && sr == r)
		return lca_tree[i];
	int sm = (sl + sr) >> 1;
	if (r <= sm)
		return lca_tree_min (i+i, sl, sm, l, r);
	if (l > sm)
		return lca_tree_min (i+i+1, sm+1, sr, l, r);
	int ans1 = lca_tree_min (i+i, sl, sm, l, sm);
	int ans2 = lca_tree_min (i+i+1, sm+1, sr, sm+1, r);
	return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}
 
int lca (int a, int b) {
	int left = lca_first[a], right = lca_first[b];
	if (left > right)  swap (left, right);
	return lca_tree_min (1, 0, (int)lca_dfs_list.size()-1, left, right);
}
 
int dfs(int v, int p, const graph& g) {
    int res = ans[v];
    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to != p) {
            res += dfs(to, v, g);
        }
    }
    return ans[v] = res;
}
 
 
int main() {
    //ios_base::sync_with_stdio(0);
    graph g;
    int root = 0;
    int n, a, b; cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &a, &b);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    lca_prepare(g, root);
 
    for(int i = 0; i < n-1; ++i) {
        int a = i, b = i + 1;
        int _lca = lca(a, b);
        if(_lca == a || _lca == b) {
            if(lca_h[a] > lca_h[b]) {
                ans[a] += 1;
                if(parent[b] >= 0) ans[parent[b]] -= 1;
            }
            else {
                ans[b] += 1;
                if(parent[a] >= 0) ans[parent[a]] -= 1;
            }
        }
        else {
            ans[a] += 1;
            ans[b] += 1;
            ans[_lca] -= 1;
            if(parent[_lca] >= 0) {
                ans[parent[_lca]] -= 1;
            }
        }
    }
 
    dfs(0, -1, g);
 
    for(int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
}
