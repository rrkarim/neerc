#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;
typedef pair<int,int> p;
typedef long long ll;
int n, m, x, y, c;
ll t[4 * MAXN], t_max[4 * MAXN], d[4 * MAXN], a[MAXN + 2];
void build (int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = t_max[v] = a[tl];
        d[v] = 0;
    }
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build ( v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
        ll x = MINF;
        if((d[v*2]==0&&d[v*2+1]==0)||(d[v*2]==2&&d[v*2+1]==1)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 3;
            if(x == t[v]) d[v] = 0;
        }
        if((d[v*2]==0&&d[v*2+1]==1)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 1;
        }
        if((d[v*2]==2&&d[v*2+1]==0)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 2;
        }
        if((d[v*2]==1&&d[v*2+1]==1)||((d[v*2]==1&&d[v*2+1]==0))) {
            x = t[v*2]+t_max[v*2+1];
            d[v] = 1;
            if(x == t[v]) d[v] = 0;
        }
        if((d[v*2]==1&&d[v*2+1]==2)||(d[v*2]==1&&d[v*2+1]==3)) {
            x = t[v*2]+t[v*2+1];
            d[v] = 0;
        }
        if((d[v*2]==0&&d[v*2+1]==2)||(d[v*2]==0&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==2)) {
            x = t_max[v*2]+t[v*2+1];
            d[v] = 2;
            if(x == t[v]) d[v] = 0;
        }
        if(t_max[v*2] > x) {
            x = t_max[v*2];
            d[v] = 1;
            if(d[v*2+1] == 2 || d[v*2+1] == 3) d[v] = 3;
        }
        if(t_max[v*2+1] > x) {
            x = t_max[v*2+1];
            d[v] = 2;
            if(d[v*2+1] == 1 || d[v*2+1] == 3) d[v] = 3;
        }
        if(t[v] > x) {
            x = t[v];
            d[v] = 0;
        }
        t_max[v] = x;
    }
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {t[v] = t_max[v] = new_val,d[v] = 0;}
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update (v*2, tl, tm, pos, new_val);
        else update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];

        ll x = MINF;
        if((d[v*2]==0&&d[v*2+1]==0)||(d[v*2]==2&&d[v*2+1]==1)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 3;
            if(x == t[v]) d[v] = 0;
        }
        if((d[v*2]==0&&d[v*2+1]==1)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 1;
        }
        if((d[v*2]==2&&d[v*2+1]==0)) {
            x = t_max[v*2]+t_max[v*2+1];
            d[v] = 2;
        }
        if((d[v*2]==1&&d[v*2+1]==1)||((d[v*2]==1&&d[v*2+1]==0))) {
            x = t[v*2]+t_max[v*2+1];
            d[v] = 1;
            if(x == t[v]) d[v] = 0;
        }
        if((d[v*2]==1&&d[v*2+1]==2)||(d[v*2]==1&&d[v*2+1]==3)) {
            x = t[v*2]+t[v*2+1];
            d[v] = 0;
        }
        if((d[v*2]==0&&d[v*2+1]==2)||(d[v*2]==0&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==2)) {
            x = t_max[v*2]+t[v*2+1];
            d[v] = 2;
            if(x == t[v]) d[v] = 0;
        }
        if(t_max[v*2] > x) {
            x = t_max[v*2];
            d[v] = 1;
            if(d[v*2+1] == 2 || d[v*2+1] == 3) d[v] = 3;
        }
        if(t_max[v*2+1] > x) {
            x = t_max[v*2+1];
            d[v] = 2;
            if(d[v*2+1] == 1 || d[v*2+1] == 3) d[v] = 3;
        }
        if(t[v] > x) {
            x = t[v];
            d[v] = 0;
        }
        t_max[v] = x;
    }
}
ll sum (int v, int tl, int tr, int l, int r) {
    if (l > r)return 0;
    if (l == tl && r == tr)return t[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm))
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
ll max_sum (int v, int tl, int tr, int l, int r) {
    if (l > r) return MINF;
    if (l == tl && r == tr) return t_max[v];
    int tm = (tl + tr) / 2;
    ll x = MINF;
    ll xl = max_sum (v*2, tl, tm, l, min(r,tm)), xr = max_sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    ll sl = sum (v*2, tl, tm, l, min(r,tm)), sr = sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    if((d[v*2]==0&&d[v*2+1]==0)||(d[v*2]==0&&d[v*2+1]==1)||(d[v*2]==2&&d[v*2+1]==1)||(d[v*2]==2&&d[v*2+1]==0)) x = xl+xr;
    if((d[v*2]==1&&d[v*2+1]==1)||((d[v*2]==1&&d[v*2+1]==0))) x = sl+xr;
    if((d[v*2]==1&&d[v*2+1]==2)||(d[v*2]==1&&d[v*2+1]==3)) x = sl+sr;
    if((d[v*2]==0&&d[v*2+1]==2)||(d[v*2]==0&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==3)||(d[v*2]==2&&d[v*2+1]==2)) x = xl+sr;
    if(xl > x) x = xl;
    if(xr > x) x = xr;
    return x;}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", a + i);
    build(1, 0, n - 1);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &c, &x, &y);
        if(c == 1)printf("%lld\n", max_sum(1, 0, n - 1, x - 1, y - 1));
        else update(1, 0, n - 1, x - 1, y);
    }
}