/**
    Rasul Kerimov (CoderINusE)
    GSS1 - Can you answer these queries I
    Segment tree
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
int n, m, x, y, c;
ll t[4 * MAXN], t_max[4 * MAXN], t_pre[4 * MAXN], t_suf[4 * MAXN], a[MAXN + 2];

struct p {
    ll t_sum, t_max, t_pre, t_suf;
    p(ll t_sum, ll t_max, ll t_pre, ll t_suf) : t_sum(t_sum), t_pre(t_pre), t_max(t_max), t_suf(t_suf) {}
};

p minf = {MINF, MINF, MINF, MINF};

void build (int v, int tl, int tr) {
    if (tl == tr) {t[v] = t_max[v] = t_pre[v] = t_suf[v] = a[tl];}
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build ( v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
        t_max[v] = max( max( t_max[v*2], t_max[v*2+1] ), (t_suf[v*2] + t_pre[v*2+1]) );
        t_pre[v] = max(t_pre[v*2], t[v*2] + t_pre[v*2+1]);
        t_suf[v] = max(t_suf[v*2+1], t_suf[v*2]+t[v*2+1]);
    }
}
/**
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {t[v] = t_max[v] = t_pre[v] = t_suf[v] = new_val;}
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update (v*2, tl, tm, pos, new_val);
        else update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
        t_max[v] = max( max( t_max[v*2], t_max[v*2+1] ), (t_suf[v*2] + t_pre[v*2+1]) );
        t_pre[v] = max(t_pre[v*2], t[v*2] + t_pre[v*2+1]);
        t_suf[v] = max(t_suf[v*2+1], t_suf[v*2]+t[v*2+1]);
    }
}
*/
p max_sum (int v, int tl, int tr, int l, int r) {
    if (l > r) return minf;
    if (l == tl && r == tr) return {t[v], t_max[v], t_pre[v], t_suf[v]};
    int tm = (tl + tr) / 2;

    p lp = max_sum (v*2, tl, tm, l, min(r,tm)), rp = max_sum (v*2+1, tm+1, tr, max(l,tm+1), r);

    ll sum = lp.t_sum + rp.t_sum;
    ll maxn = max( max(lp.t_max, rp.t_max), (lp.t_suf + rp.t_pre) );
    ll pre = max( lp.t_pre, lp.t_sum + rp.t_pre );
    ll suf = max(rp.t_suf, lp.t_suf + rp.t_sum);

    return {sum, maxn, pre, suf};

}
int main() {
    scanf("%d", &n);
    //freopen("a.txt", "w", stdout);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }
    build(1, 0, n - 1);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        printf("%lld\n", max_sum(1, 0, n - 1, x - 1, y - 1).t_max);
    }
}
