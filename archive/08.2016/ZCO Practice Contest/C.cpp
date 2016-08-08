#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 1000000
using namespace std;

typedef long long ll;
int n;
ll a[MAXN + 2], b[MAXN + 2], sum = 0, res = 0;
int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) scanf("%lld", a + i);
    sort(a, a + n);

    for(int i = 1; i < n; ++i) b[i - 1] = a[i] - a[0], sum += a[i] - a[0];
    res = sum;
    for(int i = 0; i < n - 1; ++i) {
        sum -= (n - i - 1) * (a[i + 1] - a[i]);
        res += sum;
    }
    cout << res << endl;

}
