#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 2005
#define INF 10000000000000
using namespace std;

typedef long long ll;

int n, p, q;
ll a[MAXN + 2];
int dp[MAXN + 2][MAXN + 2], sz[MAXN + 2][2];
bool solve(ll w) {
    for(int i = 0; i < n; ++i)
        sz[i][0] = lower_bound(a, a + n, a[i] + w) - a;
    for(int i = 0; i < n; ++i)
        sz[i][1] = lower_bound(a, a + n, a[i] + 2*w) - a;

    for(int i = 0; i <= p; ++i) for(int j = 0; j <= q; ++j) dp[i][j] = -11;

    dp[p][q] = 0;
    for(int i = p; i >= 0; --i) {
        for(int j = q; j >= 0; --j) {
            if(dp[i][j] == -11) continue;
            if(dp[i][j] == n) return 1;

            if(i) dp[i - 1][j] = max(dp[i - 1][j], sz[dp[i][j]][0]);
            if(j) dp[i][j - 1] = max(dp[i][j - 1], sz[dp[i][j]][1]);
        }
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(0);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &p, &q);
        for(int i = 0; i < n; ++i) scanf("%I64d", a + i);
        sort(a, a + n);

        if(p + q >= n) {
            puts("1");
            continue;
        }
        ll l = 1, r = 1e9;
        while(l < r) {
            ll m = (l + r) >> 1;
            if(solve(m)) r = m;
            else l = m + 1;
        }
        printf("%I64d\n", l);
    }
}
