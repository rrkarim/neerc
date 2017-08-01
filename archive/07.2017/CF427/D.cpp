#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 1000005

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
int dp[5005][5005], ans[5005];
string s;

int main() {
    cin >> s;
    int n = s.size();
    for(int x = 1; x <= n; ++x) {
        for(int i = 0; i <= n - x; ++i) {
            if(x == 1) dp[i][i + x - 1] = 1;
            else {
                if(s[i] != s[i + x - 1] || (x > 2 ? (dp[i + 1][i + x - 2] == 0) : false ) )
                    dp[i][i + x - 1] = 0;
                else {
                    int m = (2*i + x) / 2 - 1;
                    dp[i][i + x - 1] = dp[i][m] + 1;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            while(dp[i][j]) ans[dp[i][j]--] += 1;

    for(int i = 1; i <= s.size(); ++i ) cout << ans[i] << " "; cout << endl;
}
