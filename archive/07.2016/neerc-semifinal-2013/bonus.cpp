/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int n, m;

long double dp[3004][3004], dp1[3004][3004];
ll a, b;
int main() {
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    cin >> n >> a >> b;

    ll x = max(0ll, a - n);
    ll y = max(0ll, b - n);

    for(int i = 0; i <= (a - x); ++i) {

        for(int j = 0; j <= (b - y); ++j) {
            ll s = a - x - i + b - y - j;
            double d = 2 * (x + i) + (y + j);

            if(s >= n) {
                dp[i][j] = 0.0;
                dp1[i][j] = 0.0;
            }
            else {
                if(i == 0) {
                    double d = 2 * (x + i) + (y + j) + 2;
                    double d1 = 2 * (x + i) + (y + j) + 1;
                    long double p = 2.0 / d;
                    long double p1 = 1.0 / d1;
                    if(j - 1 >= 0) {
                        p += (double)(y + j) / d * dp[i][j - 1];
                        p1 += (double)(y + j) / d1 * dp1[i][j - 1];
                    }
                    dp[i][j] = p;
                    dp1[i][j] = p1;
                }
                else if(j == 0) {
                    double d = 2 * (x + i) + (y + j) + 2;
                    double d1 = 2 * (x + i) + (y + j) + 1;
                    long double p = 2.0 / d;
                    long double p1 = 1.0 / d1;
                    if(i - 1 >= 0) {
                        p += (double)(x + i) * 2.0 / d * dp[i - 1][j];
                        p1 += (double)(x + i) * 2.0 / d1 * dp1[i - 1][j];
                    }
                    dp[i][j] = p;
                    dp1[i][j] = p1;
                }
                else {
                    double d = 2 * (x + i) + (y + j) + 2;
                    double d1 = 2 * (x + i) + (y + j) + 1;

                    long double p = 2.0 / d;
                    long double p1 = 1.0 / d1;

                    if(j - 1 >= 0) {
                        p += (double)(y + j) / d * dp[i][j - 1];
                        p1 += (double)(y + j) / d1 * dp1[i][j - 1];
                    }
                    if(i - 1 >= 0) {
                        p += (double)(x + i) * 2.0 / d * dp[i - 1][j];
                        p1 += (double)(x + i) * 2.0 / d1 * dp1[i - 1][j];
                    }
                    dp[i][j] = p;
                    dp1[i][j] = p1;
                }
            }

        }

    }
    cout << fixed << setprecision(10) << dp[a - x][b - y] << "\n" << dp1[a - x][b - y] << endl;


}
