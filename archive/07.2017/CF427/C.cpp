#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 100

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;

int n, q, c;
vector<int> mp[MAXN+3][MAXN+3];
int x, y, s, x1, y11, x2, y2, len, sum, t, dp[MAXN+3][MAXN+3][15];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> c;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y >> s;
        mp[y][x].push_back(s);
    }
    for(int i = 1; i <= MAXN; ++i) {
        for(int j = 1; j <= MAXN; ++j) {
            len = mp[i][j].size();
            for(int z = 0; z < c + 1; ++z) {
                dp[i][j][z] += dp[i - 1][j][z] + dp[i][j - 1][z] - dp[i - 1][j - 1][z];

                if(len == 0) continue;

                sum = 0;
                for(int t = 0; t < mp[i][j].size(); ++t)
                    sum += mp[i][j][t], mp[i][j][t] = (mp[i][j][t] + 1) % (c + 1);
                dp[i][j][z] += sum;
            }
        }
    }


    for(int i = 0; i < q; ++i) {
        cin >> t;
        t %= (c + 1);
        cin >> x1 >> y11 >> x2 >> y2;
        int ans = dp[max(y11, y2)][max(x1, x2)][t];
        ans += -(dp[ max(y11, y2) ][ min(x1, x2) - 1 ][t] + dp[ min(y11, y2) - 1 ][ max(x1, x2)][t]) + dp[ min(y11, y2) - 1 ][ min(x1, x2) - 1 ][t];
        cout << ans << endl;
    }

}
