#include <bits/stdc++.h>
#define INF 1000000000000000
#define INFF 100000000000000000
using namespace std;

typedef long long ll;

int c[1000];
ll b[505][505];
ll dp[104][104][104];
int main() {

    for(int i = 0; i < 104; ++i) for(int j = 0; j < 104; ++j) for(int z = 0; z < 104; ++ z) dp[i][j][z] = INF;

    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%I64d", &b[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(c[i] == 0) {
            if(i == 1) {
                for(int j = 1; j <= m; ++j) dp[i][j][1] = b[i][j];
            }
            else {
                for(int col = 1; col <= m; ++col) {
                    for(int j = 1; j <= m; ++j) {
                        for(int z = 1; z <= k; ++z) {
                            if(dp[i - 1][j][z] == INF) continue;
                            if(j == col) {
                                dp[i][col][z] = min(dp[i][col][z], dp[i-1][j][z] + b[i][col]);
                            }
                            else {
                                dp[i][col][z + 1] = min(dp[i][col][z+1], dp[i-1][j][z] + b[i][col]);

                            }
                        }
                    }
                }
            }
        }
        else {
            if(i == 1) {
                dp[i][c[i]][1] = 0;
            }
            else {
                for(int j = 1; j <= m; ++j) {
                    for(int z = 1; z <= k; ++z) {
                        if(dp[i - 1][j][z] == INF) continue;
                        if(j == c[i]) {
                            dp[i][c[i]][z] = min(dp[i][c[i]][z], dp[i-1][j][z]);
                        }
                        else {
                            dp[i][c[i]][z + 1] = min(dp[i][c[i]][z+1], dp[i-1][j][z]);
                        }
                    }
                }
            }
        }
    }
    ll res = INF;
    for(int i = 1; i <= m; ++i) {
        if(dp[n][i][k] != INF) {
            res = min(res, dp[n][i][k]);
        }
    }

    if(res == INF) puts("-1");
    else printf("%I64d\n", res);

}