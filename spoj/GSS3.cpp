/**
    Rasul Kerimov (CoderINusE)
    GSS3 - Can you answer these queries III
    Segmented tree
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF = -1000000000000
using namespace std;
typedef pair<int,int> p;
typedef long long ll;

int n, m, x, y; char c;
ll t[4 * MAXN], t_max[4 * MAXN], d[4 * MAXN], a[MAXN + 2];
/**
    0 - both
    1 - left
    2 - right
    3 - middle
*/
void build (int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = t_max = a[l];
        d[v] = 0;
    }
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build ( v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
        t_max[v] = t[v]; //both
        d[v] = 0;
        if(t_max[v * 2] > t_max[v]) { //left
            t_max[v] = t_max[v * 2];
            d[v] = 1;
        }
        if(t_max[v*2+1] > t_max[v]) { //right
            t_max[v] = t_max[v * 2];
            d[v] = 2;
        }
        if(t_max[v*2] + t_max[v*2+1] > t_max[v]) { //middle
            t_max[v] = t_max[v*2] + t_max[v*2+1];
            d[v] = 3;
            if(t_max[v*2] == t[v*2]) d[v] = 1;
            else if(t_max[v*2+1] == t[v*2+1]) d[v] = 2;
        }
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

ll sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t_max[v];
    int tm = (tl + tr) / 2;
    ll x = MINF;
    if((d[v*2] == 0 && d[v*2+1] == 0) || (d[v*2] == 2 && d[v*2+1] == 0)
        || (d[v*2] == 2 && d[v*2+1] == 1) || (d[v*2] == 0 && d[v*2+1] == 1) ) {
        x = sum (v*2, tl, tm, l, min(r,tm))
            + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    }
    x = max(sum (v*2, tl, tm, l, min(r,tm))
            ,sum (v*2+1, tm+1, tr, max(l,tm+1), r));

    return x;
}

ll max_sum(int v, int tl, int tr, int l, int r) {

}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%lld", a + i);
    build(1, 0, n - 1);
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%c%d%d", &c, &x, &y);
        if(c == 1)
            printf("%lld\n", max_sum(1, 0, n - 1, x - 1, y - 1));
        else
            update(1, 0, n - 1, x - 1, y);
    }
}
