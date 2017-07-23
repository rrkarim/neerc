/*
	Barrels and boxes
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200005

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int , int > ii ;

const ll mod = 1e9 + 7;

pair <int, int> dp[MAXN + 2];
ll f, w, h;
ll pre_mul[MAXN + 2];

ll binpow (ll a, ll n) {
	if (!n) return 1ll;
	if (n % 2 == 1) return (binpow (a, n-1) * a) % mod;
	else {
		ll b = binpow (a, n/2) % mod;
		ll res = (b * b) % mod;
		return res;
	}
}
ll inverse(ll n) {
    ll res = binpow(n, mod - 2);
    return res;
}

ll C_(const ll& n, const ll& m) {
    if(m < 0 || n < 0 || n < m) return 0;
    ll res = pre_mul[n];
    res = (res * (inverse(pre_mul[m]) % mod * inverse(pre_mul[n - m]) % mod) ) % mod;
    return res;
}

int main() {
    scanf("%d%d%d", &f, &w, &h);
    ll ans = 0;
    pre_mul[0] = 1, pre_mul[1] = 1;
    for(int i = 2; i <= MAXN; ++i) pre_mul[i] = (pre_mul[i - 1] * i) % mod;
    for(int i = 1; i <= f + 1; ++i) {
        ans = (ans + (C_(f + 1, i) * C_(w - i*(h + 1) + i - 1, i - 1)) % mod ) % mod;
    }
    if(w == 0) ans = 1;
    
    printf("$lld", (ans * inverse( C_(w + f, f) ) % mod) % mod );
}
