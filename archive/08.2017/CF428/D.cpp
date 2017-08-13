#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200004

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

vector <vector <int>> g;
int u, v;

int prime[MAXN*5 + 1000], zs = 0;
int mp[MAXN*5 + 1000];


ll binpow (ll a, ll n) {
	if (n == 0) return 1ll;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a) % mod;
	else {
		int b = binpow (a, n/2);
		return (b * b) % mod;
	}
}

void erat(int n) {
    memset(prime, -1, sizeof prime);

    for (int i = 2; i <= n; ++i) {
        if (prime[i] == -1) {
            if (i * 1ll * i <= n)
                for (int j = i*i; j <= n; j += i)
                    prime[j] = i;
        }
    }
}

vector <int> vi;
unordered_map <int, int> ms;

int main() {
    ios_base::sync_with_stdio(0);
    erat(1e6);

    int n, x_; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x_;
        if(x_ > 1) vi.push_back(x_);
    }

    for(int i = 0; i < vi.size(); ++i) {
        int x = vi[i];
        while(true) {
            if(prime[x] == -1) {
                if(ms[x] == 0) mp[x] += 1;
                break;
            }
            else {
                if(ms[ prime[x] ] == 0) {
                    mp[prime[x]] += 1;
                    ms[ prime[x] ] = 1;
                }
                x = x / prime[x];
            }
        }
        ms.clear();
    }

    ll ans = 0;

    for(int i = 2; i <= MAXN*5; ++i) {
        if(mp[i] >= 1) {
            ll x = (mp[i] * binpow(2, mp[i] - 1)) % mod;
            x = (x * i) % mod;
            x = (x - (mp[i] * i) % mod + mod) % mod;
            ans = (ans + x) % mod;
        }
    }
    for(int i = 0; i < vi.size(); ++i) {
        ans = (ans + vi[i]) % mod;
    }
    cout << ans << endl;
}