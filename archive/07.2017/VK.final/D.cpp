/**
* DID YOU GET WHAT YOU WANTED FROM THIS LIFE?
* I DID....
* AND WHAT DID YOU WANT?
* TO CALL MYSELF BELOVED.
* TO FEEL MYSELF BELOVED ON THE EARTH....
*/
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 402

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

/*
void input() {

    cin >> n >> k >> b;
    for(int i = 0; i < n; ++i) {
        cin >> a_ >> b_;
        d[i] = {a_, b_};
    }
    sort(d, d + n, cmp);
    for(int i = 0; i < n; ++i) {
        if(d[i].first == 1) {
            ;d1[]
        }
        else {

        }
    }

}
*/

ll dp[MAXN + 2][MAXN + 2]; int k;

int main() {
    scanf("%d", &k);
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= k; ++i) {
        for(int j = 0; j <= k - i + 1; ++j) {
            dp[i][j] = dp[i - 1][0] * dp[i - 1][j] % mod;
            for(int z = 0; z < j; ++z) {
                dp[i][j] = (dp[i][j] + (dp[i - 1][z] * dp[i - 1][j - z - 1]) % mod ) % mod;
                dp[i][j] = (dp[i][j] + (dp[i - 1][z + 1] * dp[i - 1][j - z]) % mod * ((z + 1) * (j - z) * 2ll)) % mod;
                dp[i][j] = (dp[i][j] + (dp[i - 1][z + 1] * dp[i - 1][j - z - 1]) % mod * (4ll * z + 5ll) ) % mod;
                dp[i][j] = (dp[i][j] + (dp[i - 1][z + 2] * dp[i - 1][j - z - 1]) % mod * (2 * (z + 2) * (z + 1)) ) % mod;
            }
        }
    }
    cout << dp[k][1] << endl;
}