#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
using namespace std;

typedef long long ll;

ll pw(int x) {
    ll res = 1;
    for(int i = 0; i < x; ++i) res *= 4;
    return res;
}

int main() {
    ll n; cin >> n;
    ll x = sqrt(n*1.0);
    if(x * x == n) cout << 1 << endl;
    else {
        ll sq = sqrt(n);
        for(ll i = 1; i <= sq; ++i) {
            ll t = n - i * i, xz = sqrt(t*1.0);
            if(xz * xz == t) {
                cout << 2 << endl;
                return 0;
            }
        }

        ll m = 0, z = 1;

        while(n % 4 == 0) {
            n /= 4;
        }

        if((n + 1) % 8 == 0) {
            cout << 4 << endl;
            return 0;
        }

        cout << 3 << endl;

    }
}
