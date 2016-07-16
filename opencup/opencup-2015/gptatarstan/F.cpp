/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 9ll;

ll k, d, m, last_a, last_b, ans = 1;
vector <int> a(MAXN + 2), b(MAXN + 2);
int last = MAXN;

void get_v(vector<int>& d, ll n, ll& last_value) {
    for(int i = 2; i <= (int)sqrt(n) + 1; ++i) {
        while(n % i == 0) {
            d[i] += 1;
            n /= i;
        }
    }
    if(n) d[(n > MAXN ? last : n)] = 1;
    if(n > MAXN) last_value = n;
}

ll binpow(int n, ll k) {
    if(k == 0) return 1ll;
    if(k % 2) return (binpow(n, k - 1) * n) % mod;
    else {
        ll res = binpow(n, k / 2) % mod;
        return (res * res) % mod;
    }
}

ll mod_(const ll& a) {
    if(a >= 0) return a % mod;
    else return mod + a;
}

ll func(const int& a, const int& b) {
    assert(b > a);
    ll p1 = binpow(b - a + 1, k) % mod;
    ll p2 = 2ll * binpow(b - a, k) % mod;
    ll p3 = binpow(b - a - 1, k) % mod;
    return mod_((p1 + p3) % mod - p2);
}

int main() {
    cin >> k >> d >> m;
    get_v(a, d, last_a); get_v(b, m, last_b);

    for(int i = 2; i <= MAXN - 3; ++i) {
        if(b[i] > a[i]) {
            ll t = func(a[i], b[i]);
            //assert(t >= 0);
            ans = (ans * t) % mod;
        }
        else if(b[i] < a[i]) {
            ans *= 0;
            break;
        }
    }

    if(a[last] && !b[last]) {
        ans *= 0;
    }
    else if(b[last] && !a[last]) {
        ans = (ans * func(0, b[last])) % mod;
    }
    else if(last_a && last_b) {

        if(last_a != last_b) ans *= 0;
        else
        if(b[last] > a[last]) {
            ans = (ans * func(a[last], b[last])) % mod;
        }
        else if(b[last] < a[last]) ans *= 0;
    }
    assert(ans >= 0);
    cout << ans << endl;
}
