#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
using namespace std;
typedef long long ll;

double dp[16][20][20];
int n, f[20], c[20];
int t[14][15], k;
string sr;

int convert(string s) {
    int res = 0, d = 1;
    for(int i = s.size()-1; i >= 0; --i) {
        res += d * (s[i] - '0');
        d *= 10;
    }
    return res;
}

int main() {
    //ios_base::sync_with_stdio(0);

    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> f[i] >> c[i];
        for(int j = 0; j < c[i]; ++j) {
            cin >> sr;
            if(sr[0] == '+') {
                t[i][j] = -convert(sr.substr(1));
            }
            else {
               t[i][j] = convert(sr);
            }
        }
    }
    cin >> k;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            for(int z = 0; z <= f[i]; ++z) {

                if(j == 0) {
                    dp[i][j][z] = 1.0;
                    if(z == 0) dp[i][j][z] = 0.0;
                }
                else {
                    if(z > 0) {
                        for(int x = 0; x < c[i]; ++x) {
                            if(t[i][x] > 0) {
                                double xz = dp[i][max(0, j - t[i][x])][z-1];
                                if(z - 1 == 0 && (j - t[i][x] < 0)) {
                                    xz = 1.0;
                                }
                                dp[i][j][z] += xz / (double)c[i];
                            }
                            else {
                                dp[i][j][z] += dp[i][max(0, j - abs(t[i][x]))][z] / (double)c[i];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << dp[0][0][1] << endl;
}
