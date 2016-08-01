/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, m, dp[30][30], used[MAXN + 2], x, y, r, q, t, index[MAXN + 2];
int a[MAXN + 2];
char c[5];

multiset <int> S;
set <int>::iterator it, it1;
set <int> ind[MAXN + 2];
vector <int> xin[MAXN + 2];
int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    /*
    int n, m; cin >> n >> m;
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j)
            cin >> dp[i][j];
    */
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ind[a[i]].insert(i + 1);
    }
    for(int i = 0; i < n; ++i) S.insert(a[i]);
    for(int i = 0; i < q; ++i) {

        scanf("%s%d", &c, &t);
        if(c[0] == 'i') {
            it = S.lower_bound(t);
            if(it == S.end()) {
                cout << "-1" << endl;
                continue;
            }
            else {
                S.erase(it);
                it1 = ind[*it].begin();
                cout << *(it1) << endl;
                ind[*it].erase(it1);
            }
        }
        else {
            S.insert(a[t - 1]);
            ind[a[t - 1]].insert(t);
        }

    }
}
