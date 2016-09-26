#include <bits/stdc++.h>
#define in(x) scanf("%d" ,&x)
#define IN(x) scanf("%I64d" , &x)
#define ll long long
#define all(a) memset(a , 0 , sizeof a)
#define ull unsigned long long
#define pii pair<int , int>
using namespace std;
const ll mod = 1e9+7;
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd ( ll a, ll b ){ll c;  while ( a != 0 ) { c = a; a = b%a;  b = c;}return b;};
ll lcm ( ll a , ll b) {return a / gcd(a , b) * b;}

pair<int, vector <int> > t[500];
int coun[500];
int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
int main() {
    int m, n, x;
    cin >> m >> n;
    g.resize(1000);
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for(int j=0;j<t;++j){
            int v2;
            cin >> v2;
            g[i+1].push_back(200+v2);
            g[200+v2].push_back(i+1);
        }
    }

    mt.assign (1000, -1);
	for (int v = 1; v <= n; ++v) {
		used.assign (1000, false);
		try_kuhn (v);
	}
    int res = 0;
	for (int i = 201; i <= 200+m; ++i)
		if (mt[i] != -1)
            res += 1;

    cout << res << endl;
}

