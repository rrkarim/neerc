/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, m, dp[30][30], used[MAXN + 2], x, y, r, q, t, index[MAXN + 200];
int a[MAXN + 200];
char c[10];

multiset <int> S;
set <int>::iterator it, it1;
set <int> ind[MAXN + 200];

int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    /*
    int n, m; cin >> n >> m;
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j)
            cin >> dp[i][j];
    */
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ind[a[i]].insert(i + 1);
    }
    for(int i = 0; i < n; ++i) S.insert(a[i]);
    for(int i = 0; i < q; ++i) {

        scanf("%s%d", &c, &t);
        if(c[0] == 'i') {
            it = S.lower_bound(t);
            int x = *it;
            if(it == S.end()) {
                printf("-1\n");
                continue;
            }
            else {
                S.erase(it);
                it1 = ind[x].begin();
                int y = *it1;
                printf("%d\n", y);;
                ind[x].erase(it1);
            }
        }
        else {
            S.insert(a[t - 1]);
            ind[a[t - 1]].insert(t);
        }

    }
}