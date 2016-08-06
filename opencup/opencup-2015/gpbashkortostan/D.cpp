#include <bits/stdc++.h>
#define MAX_CHAR 256
#define INF -1000000000000
#define MAXN 100000
#define MAXN_ 1500000
using namespace std;
typedef long long ll;
int n, x[MAXN + 2];
ll w, a[MAXN + 2], t[MAXN * 4 + 10], ma[MAXN * 2 + 2];

void build (int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

ll maxn (int v, int tl, int tr, int l, int r) {
	if (l > r) return INF;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) / 2;
	return max(maxn (v*2, tl, tm, l, min(r,tm)), maxn (v*2+1, tm+1, tr, max(l,tm+1), r));
}


int solve() {
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        ma[i] = a[i];
        res += a[i] + 1;
    }
    res -= 1;
    if(res <= w) return 1;
    int k = 0;
    res = 0;
    for(int i = 0; i < n / 2; ++i) {
        if(i == n / 2 - 1) {
            if(n % 2) ma[n + i] = ma[k];
            else ma[n + i] = max(ma[k], ma[k + 1]);
        }
        else ma[n + i] = max(ma[k], ma[k + 1]);
        k += 2;
        res += ma[n + i] + 1;
    }
    if(n % 2) res += ma[n - 1] + 1;
    res -= 1;
    if(res <= w) return 2;
    for(int i = 3; i <= n; ++i) {
        ll sum = 0;
        int index = 0;
        for(int j = 0; j < x[i]; ++j) {
            if(j == x[i] - 1) {
                if(n % i == 0) {
                    sum += maxn(1, 0, n - 1, index, index + i - 1) + 1ll;
                }
                else {
                    sum += maxn(1, 0, n - 1, index, index + n % i - 1) + 1ll;
                }
            }
            else {
                sum += maxn(1, 0, n - 1, index, index + i - 1) + 1ll;
            }
            index += i;
        }
        sum -= 1;
        if(sum <= w) return i;
    }
    return -1;
}

int main() {
    //ios_base::sync_with_stdio(0);
    cin >> n >> w;
    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(int i = 1; i <= n; ++i) {
        x[i] = n / i + (n % i != 0);
    }
    build(1, 0, n - 1);
    cout << solve() << endl;

}
