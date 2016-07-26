#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
int n, m, a[505];
int main() {
    //freopen("a.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    ll sum = (n + 1) * n / 2;
    ll s = sum - m;
    if(s % 2 != 0) {
        printf("Impossible\n");
        return 0;
    }
    s /= 2;
    for(int i = n; i >= 2; --i) {
        if(s - i >= 0) {
            a[i] = 1;
            s -= i;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 1) printf("-");
        else if(i != 1) printf("+");
        printf("%d", (i));
    }
    printf("\n");
}
