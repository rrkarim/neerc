#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

int used[MAXN + 2];
vector<vector <int> > vi;
pair <int, int> a[MAXN + 2];

int n, t[4 * MAXN];

void build (int v, int tl, int tr) {
	if (tl == tr) t[v] = 1;
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

int main() {
    int t, n; cin >> t;
    for(int i = 0; i < t; ++i) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].first);
        for(int i = 0; i < n; ++i) scanf("%d", &a[i].second);
        sort(a, a + n);
        build(1, 0, n - 1);

        for(int i = 0; i < n; ++i) {
            int gl = a[i].second + 1;
            int l = 0, r = n - 1, m;

            while(l <= r) {
                if(l + 1 == r) {
                    if(sum(1, 0, n - 1, 0, l) != gl) l = r;
                    break;
                }
                m = (l + r) / 2;
                int x = sum(1, 0, n - 1, 0, m);
                if(x >= gl) {
                    r = m;
                }
                else {
                    l = m;
                }
            }
            used[l] = a[i].first;
            update(1, 0, n - 1, l, 0);
        }
        for(int i = 0; i < n; ++i) printf("%d ", used[i]);
        printf("\n");
        memset(used, 0, sizeof used);
    }
}
