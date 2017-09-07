#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 1000005

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
const double eps = 1e-8;
const int N = 105;
//

int n, m, l, a[MAXN], b[MAXN], c[MAXN], a_[N], b_[N], c_[N];

class matrix {
public:	
	int a[N][N];
	matrix() {
        memset(a, 0, sizeof a);	
	}
	matrix operator* (const matrix& ma) const {
		matrix ret;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < m; ++k)
                    ret.a[i][j] = (ret.a[i][j] + 1ll*a[i][k]*ma.a[k][j]) % mod;
		}	
        return ret;
	}
};

ostream& operator <<(ostream &o, const matrix& mu) { 
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j)
            o << mu.a[i][j] << ' ';
        o << '\n';
    }
}

int main() {
#ifdef CL
    freopen("input", "r", stdin);
#endif
    //ios_base::sync_with_stdio(false);
    cin >> n >> l >> m;
    matrix ans, mu;
    for(int i = 0; i < n; ++i) cin >> a[i], a_[a[i]] += 1;
    for(int i = 0; i < n; ++i) cin >> b[i], b_[b[i]] += 1;
    for(int i = 0; i < n; ++i) cin >> c[i], c_[(c[i]+b[i])] += 1;

    for(int i = 0; i < m; ++i)
        ans.a[i][i] = 1;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            mu.a[i][(i + j) % m] = b_[j];
    l -= 2;
    for(;l;l >>= 1,mu = mu*mu) 
        if(l&1) ans=ans*mu;
    ll sum = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j)
            sum = (sum + 1ll*a_[i]*ans.a[i][j]%mod*c_[(m-j)%m])%mod;
    }
    cout << sum << endl;

}
