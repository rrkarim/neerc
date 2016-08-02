/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
ll ks[MAXN + 2];
ll a[MAXN + 2][10], used[10];
ll x[10] = {1, 5, 10, 20, 50}, n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &ks[i]);
        for(int j = 0; j < 5; ++j) scanf("%I64d", &a[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        ll sum = 0, k = ks[i];
        for(int j = 0; j < 5; ++j) {
            sum += a[i][j] * x[j];
        }
        sum -= k;
        for(int j = 4; j >= 0; --j) {
            if( sum >= x[j] ) {
                ll d = sum / x[j];
                d = min(d, used[j]);
                sum -= d * x[j];
                used[j] -= d;
            }
        }
        if(sum != 0) {
            printf("no\n");
            exit(0);
        }
        for(int j = 0; j < 5; ++j) used[j] += a[i][j];
    }

    printf("yes\n");
}
