/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000

typedef long long ll;
using namespace std;
int n, m, t[MAXN + 2], d[MAXN + 2], tot, tmp;
ll ans;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void calc(int x) {
	int i;
	for (i = 1; i*i < x; i++)
        if (x % i == 0) d[++tot] = i, d[++tot] = x/i;
	if (i*i == x) d[++tot] = i;
}
int main() {
    cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> t[i];
	sort(t + 1,t + n + 1);
	tmp = t[n] - 1;
	for (int i = n - 1; i > 0; i--) tmp = gcd(tmp, t[i] - 1);
	calc(tmp);
	for (int i = 1; i <= tot; i++)
		if (d[i] & 1)
			for (int j = d[i]; j <= m;j <<= 1)
                ans = ans + 1LL*(m - j);
	cout << ans << endl;
	return 0;
}
