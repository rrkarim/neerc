/*
    Eternal vigilance is the price of liberalizm
*/
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 3000004

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;


int n, m, a[MAXN + 2], ax[MAXN + 2], u_, v_, o, z, root = -1, chance, u[MAXN + 2], cx;
vector <pair<int, int> > g[MAXN + 2];
vector <int> ans;
map <pair<int, int>, int> mp;

void dfs(int v , int p){
	u[v] = 1;
	if(a[v] == 1) cx ++, ax[v] ++;
	for(const auto& temp : g[v]){
		int to = temp.first , label = temp.second;
		if(u[to]) continue;
		dfs(to , v);
		if((ax[to] % 2 ) == 1) ans.push_back(label) , ax[v] += 1;
	}
	ax[v] %= 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] == 1) o += 1;
        else if(a[i] == 0) z += 1;
        else chance += 1;
    }
    for(int i = 0; i < m; ++i) {
        cin >> u_ >> v_;
        if(mp[ {max(u_,v_), min(u_, v_)} ]) continue;
        g[u_].push_back({v_, i + 1});
        g[v_].push_back({u_, i + 1});
        mp[ {max(u_,v_), min(u_, v_)} ] = 1;
    }

    for(int i = 1; i <= n; ++i)
        if(!u[i] && a[i] == -1) dfs(i, -1);

    for(int i = 1; i <= n; ++i) if(u[i] == 0) {
        cx = 0;
        dfs(i, -1);
        if(cx  % 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i << '\n';

    dfs(root, -1);


    return 0;
}



