/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, k, used[MAXN + 2];
ll a[MAXN + 2];

bool cmp(const pair <ll, int>& l, const pair <ll, int>& r) {
    return l.second < r.second;
}
bool check(ll nx) {
    ll x = -1;
    int s = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > x) {
            x = a[i] + nx - 1;
            s += 1;
        }
    }
    if(s > k) return 0;
    return 1;
}
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; ++i) scanf("%I64d", a + i);
        ll l = 1, r = (a[n - 1] - a[0] + 1) / k + 2;

        while(l < r) {
            if(l == r - 1) {
                if(!check(l)) l = r;
                break;
            }
            ll m = (l + r) / 2;
            if(check(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }

        }
        printf("%I64d\n", l);

    }
}
