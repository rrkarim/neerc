
/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
#include <bits/stdc++.h>
#define sz(x) (x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define ___WTHIT___ main
//#include <boost/accumulators/accumulators.hpp>
//#include <dirent.h>
//#include <stdio.h>
//#pragma comment(linker, "/STACK:16777216")
//#define M 300002
//#define pi 3.14159265358979323846
#define MINF -2000000000
//#define M  100005
#define K 28
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fort(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

using namespace std;
typedef long long ll;
//typedef long long ull;
//const ll INF = 1.e18 + 2;
//const ll mod = 1000006;
const int MAXN = 600005;
using namespace std;
typedef vector <int> vectortemp;
typedef pair <int, int> pairtemp;
struct edge {
  int a, b, l, r;
};
int cnt[MAXN + 1], answer[MAXN], u[MAXN], color[MAXN], deg[MAXN];
vectortemp g[MAXN];
void dfs(int v, int value) {
  u[v] = 1, color[v] = value;
  for(int i = 0; i < g[v].size(); ++i)
    if (!u[g[v][i]])
      dfs(g[v][i], value);
}
void go( int l, int r, const vector <edge> &v, int vectorsize, int add_vectorsize ) {
  if (cnt[l] == cnt[r]) return;
  if (!v.size()) {
    while (l < r) answer[l++] = vectorsize + add_vectorsize;
    return;
  }
  vector <edge> v1;
  for(int i = 0; i < vectorsize; ++i)
    g[i].clear();
  for(int i = 0; i < v.size(); ++i)
    if (v[i].a != v[i].b) {
      if (v[i].l <= l && r <= v[i].r) g[v[i].a].push_back(v[i].b), g[v[i].b].push_back(v[i].a);
      else if (l < v[i].r && v[i].l < r)
        v1.push_back(v[i]);
    }

  int vectorsize1 = 0;
  for(int i = 0; i < vectorsize; ++i) u[i] = 0;
  for(int i = 0; i < vectorsize; ++i)
    if (!u[i]) deg[vectorsize1] = 0, dfs(i, vectorsize1++);
  for(int i = 0; i < v1.size(); ++i) {
    v1[i].a = color[v1[i].a];
    v1[i].b = color[v1[i].b];
    if (v1[i].a != v1[i].b)
      deg[v1[i].a]++, deg[v1[i].b]++;
  }
  vectorsize = vectorsize1, vectorsize1 = 0;
  for(int i = 0; i < vectorsize; ++i)
    u[i] = vectorsize1, vectorsize1 += (deg[i] > 0), add_vectorsize += !deg[i];
  for(int i = 0; i < v1.size(); ++i) v1[i].a = u[v1[i].a], v1[i].b = u[v1[i].b];
  int m = (l + r) / 2;
  go(l, m, v1, vectorsize1, add_vectorsize);
  go(m, r, v1, vectorsize1, add_vectorsize);
}
map <pairtemp, int> m, x;
map <int, pairtemp> m2;
int main() {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      ios_base::sync_with_stdio(0);
      vector <edge> v;
      int n, k, mm, a, b;
      cin >> n >> mm;
      for(int i = 0; i < mm; ++i) {
            cin >> a >> b; a--, b--;
            if (a > b) swap(a, b);
            m[mp(a, b)] = i;
            x[mp(a, b)] += 1;
            m2[i] = mp(a, b);
            cnt[i + 1] += cnt[i];
      }
      cin >> k; k*=2;
      for(int i = mm; i < mm + k; ++i) {
        cin >> a; a -= 1;
        if(x[m2[a]] > 1) {
            x[m2[a]] -= 1;
            cnt[i + 1] += cnt[i];
            i += 1;
            cnt[i + 1]++;
            cnt[i + 1] += cnt[i];
            continue;
        }
        int &j = m[m2[a]];
        v.push_back({m2[a].first, m2[a].second, j, i});
        j = -1;
        cnt[i + 1] += cnt[i];
        i += 1;
        cnt[i + 1]++;
        cnt[i + 1] += cnt[i];
      }
      fort(it, m)
        if (it->second != -1)
          v.push_back({it->first.first, it->first.second, it->second, k + mm});

      go(0, k + mm, v, n, 0);
      int kz = 0;
      for(int i = 0; i < k + mm; ++i) {
        if (cnt[i + 1] != cnt[i]) {
            if(kz != 0) cout << " ";
            cout << answer[i];
            kz += 1;
        }
      }
      cout << endl;
}
