#include <bits/stdc++.h>
#include <string>
#define MAXN 200010
#define MINF -100001
using namespace std;
typedef long long ll;

int n; ll s;
ll a[MAXN + 2], pre_sum = 0;
pair<ll, int> pre[MAXN + 2];
map<int, int> to_w;

int t[MAXN*4];

void build (int v, int tl, int tr) {
	if (tl == tr) t[v] = pre[tl].second;
	else {
		int tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
		t[v] = max(t[v*2] , t[v*2+1] );
	}
}

int maxn (int v, int tl, int tr, int l, int r) {
	if (l > r) return MINF;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) / 2;
	return max( maxn(v*2, tl, tm, l, min(r,tm))
		, maxn (v*2+1, tm+1, tr, max(l,tm+1), r) );
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = max(t[v*2] , t[v*2+1]);
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for(int i = 0; i < n; ++i) cin >> a[i];
    pre[0] = {a[0],0};
    for(int i = 1; i < n; ++i) pre[i] = {pre[i - 1].first + a[i],i};
    sort(pre, pre + n);
    for(int i = 0; i < n; ++i) {
        to_w[pre[i].second] = i;
    }


    build(1, 0, n - 1);

    int ans = -1, ld = -1, rd = -1;

    for(int i = 0; i < n; ++i) {
        int l = 0, r = n - 1;
        while(l < r) {
            if(l == r - 1) break;
            int m = (l + r) / 2;
            if( pre[m].first - pre_sum > s) {
                r = m - 1;
            }
            else {
                l = m;
            }
        }
        if(pre[r].first - pre_sum <= s) l = r;

        if(pre[l].first - pre_sum > s) {
            update(1, 0, n - 1, to_w[i], -1);
            pre_sum += a[i];
            continue;
        }

        int index = maxn(1, 0, n - 1, 0, l);

        if(index < i) {
            update(1, 0, n - 1, to_w[i], -1);
            pre_sum += a[i];
            continue;
        }

        int ans_temp = index - i + 1;
        if(ans_temp > ans) {
            ans = ans_temp;
            ld = i, rd =  n - index - 1;
        }


        update(1, 0, n - 1, to_w[i], -1);
        pre_sum += a[i];


    }
    if(ans == -1) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
        cout << ld << " " << rd << endl;
    }

}

