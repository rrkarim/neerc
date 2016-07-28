/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, k, a[105], x[105];
pair <int, int> dp[105];
int sum(ll x) {
    int s = 0;
    while(x % 2 == 0) {
        s += 1, x /= 2;
    }
    return s;
}
int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        scanf("%d", &n);
        for(int j = 0; j < n; ++j) dp[j] = {-1, -1};
        for(int i = 0; i < n; ++i) {
            scanf("%d", x + i);
            a[i] = sum(x[i]);
        }
        for(int i = 0; i < n; ++i) {
            dp[i] = {a[i], x[i]};
            for(int j = 0; j < i; ++j) {
                if(dp[j].second < x[i] && dp[j].first + a[i] > dp[i].first) {
                    dp[i].first = dp[j].first + a[i];
                    dp[i].second = x[i];
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i) res = max(res, dp[i].first);
        printf("%d\n", res);

    }
}