/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define NMAX 1002
#define INF 1000000000
#define first x
#define second y
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int n;
ll s, a[20 + 2];
int dp[(1 << 20) + 2];
ll sum[(1 << 20) + 2];

struct sp {
    int first, second;
};

sp parent[(1 << 20) + 2];
int ones[(1 << 20) + 2];

int funcF(int mask) {
    if(sum[mask] <= s) {
        ones[mask] = 1;
        parent[mask].x = mask;
        return dp[mask] = 1;
    }
    if(dp[mask] != -1) return dp[mask];
    dp[mask] = INF;
    for(int i = (mask - 1) & mask; i >= mask ^ i; i = (i -  1) & mask) {
        int x = funcF(i) + funcF(mask ^ i);
        if(x < dp[mask]) {
            dp[mask] = x;
            ones[mask] = 0;
            parent[mask].x = i;
            parent[mask].y = mask ^ i;
        }
    }
    return dp[mask];
}

void f_child(int mask) {
    if(ones[mask] == 1) {
        int k = 0;
        printf("%d ", __builtin_popcount(mask));
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) continue;
            if(k) putchar(' ');
            printf("%d", i + 1);
            k += 1;
        }
        putchar('\n');
        return;
    }
    f_child(parent[mask].x);
    f_child(parent[mask].y);
    return;
}

int main() {

    //freopen("input.txt", "r", stdin);
    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < (1 << 20); ++i) dp[i] = -1;
        memset(sum, 0, sizeof sum);
        scanf("%d%lld", &n, &s);
        for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);

        for(int i = 0; i < (1 << n); ++i) {
            ll c = 0;
            for(int j = 0; j < n; j += 1)
                if(i & (1 << j)) sum[i] += a[j];
        }
        printf("%d\n", funcF( (1 << n) - 1 ));
        f_child((1 << n) - 1);
        //printf("sdsdss\n");
    }
}
