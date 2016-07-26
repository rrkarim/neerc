/**
    Rasul Kerimov (CoderINusE)
    GSS3 - Can you answer these queries III
    Segmented tree
*/
#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;
typedef pair<int,int> p;
typedef long long ll;

int n, m, x, y; char c;
ll t[4 * MAXN], ll t_max[4 * MAXN], a[MAXN + 2];
void build (int v, int tl, int tr) {
    if (tl == tr) t[v] = a[l];
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build ( v*2+1, tm+1, tr);
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

ll sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm))
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
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
