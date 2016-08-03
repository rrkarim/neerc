/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int a[MAXN + 2], x, y, user[MAXN + 2], used[MAXN + 2];
int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    /*
    int n, m; cin >> n >> m;
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j)
            cin >> dp[i][j];
    */
    int n,m , q;
    cin >> n >> m >> q;
    int c = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        used[a[i]] += 1;
        if(used[ a[i] ] == 1) c += 1;
        user[i + 1] = a[i];
    }
    for(int i = 0; i < q; ++i) {

        scanf("%d%d", &x, &y);
        used[ user[x] ] -= 1;
        used[y] += 1;
        if(used[ user[x] ] == 0) {
            if(used[y] != 1) c -= 1;
        }
        else {
            if(used[y] == 1) c += 1;
        }
        user[x] = y;
        scanf("%d\n", m - c);

    }
}
