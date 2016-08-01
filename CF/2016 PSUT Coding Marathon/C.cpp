/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, m, dp[30][30], used[1000], x, y, r;
int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    /*
    int n, m; cin >> n >> m;
    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j)
            cin >> dp[i][j];
    */
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        r += y - x;
    }
    cout << r << endl;
}