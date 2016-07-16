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

const ll mod = 1e9 + 9;

ll k, d, m, last_a, last_b, ans = 1;
vector <int> a(MAXN + 2), b(MAXN + 2);
int last = 100003;

void get_v(vector<int>& d, ll n, ll& last_value) {
    for(int i = 2; i <= (int)sqrt(n); ++i) {
        while(n % i == 0) {
            d[i] += 1;
            n /= i;
        }
    }
    if(n) d[(n > MAXN ? last : n)] = 1;
    if(n > MAXN) last_value = n;
}

ll binpow(ll n, ll k) {
    if(!k) return 1;
    if(k % 2) return binpow(n, k - 1) * n % mod;
    else {
        ll res = binpow(n, k / 2);
        return res * res % mod;
    }
}

ll func(const ll& a, const ll& b) {
    return ( binpow(b - a + 1, k) - 2ll * binpow(b - a, k) + binpow(b - a - 1, k) ) % mod;
}

int main() {
    
}
