//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 10000

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int , int > ii ;

const ll mod = 1e9 + 7;
double dp[MAXN + 2][MAXN/10 + 2];
int k, q, m, ans;

int main() {
    cin >> k >> q;
    dp[0][0] = 1;
    for(int i = 1; i < MAXN + 2; ++i ) {
        for(int j = 1; j <= k; ++j) dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (k - j + 1)) / k;
    }
    while(q--) {
        cin >> m;
        for (ans = 1; dp[ans][k] * 2000 + 1e-7 < m; ans++);
		cout << ans << endl;
    }
}
