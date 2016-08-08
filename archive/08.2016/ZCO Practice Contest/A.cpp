#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 500005
#define INF 1000000
using namespace std;

typedef long long ll;
vector <ll> a;
vector <ll>::iterator it;
ll res = 0;
int n;
int main() {
    cin >> n;
    a.resize(n + 1);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i <= n; ++i) {
        ll x = a[i];
        it = lower_bound(a.begin(), a.end(), x);
        int d = distance(it, a.end());
        res = max(res, 1ll * d * x);
    }
    cout << res << endl;
}
