/*
    Maximal Rectangle leetcode
    O(n^5) - DP
*/
class Solution{
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int dp[n+1][m+1];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) {
                    if(matrix[i][j] == '1') dp[i][j] = 1;
                    else dp[i][j] = 0;
                    continue;
                }
                if(i == 0) {
                    if(matrix[i][j] == '1') {
                        int x = 0;
                        for(int z = j; z >= 0; --z) {
                            if(matrix[i][z] == '0') break;
                            x += 1;
                        }
                        dp[i][j] = max(dp[i][j-1], x);
                    }
                    else dp[i][j] = dp[i][j-1];
                }
                else if(j == 0) {
                    if(matrix[i][j] == '1') {
                        int x = 0;
                        for(int z = i; z >= 0; --z) {
                            if(matrix[z][j] == '0') break;
                            x += 1;
                        }
                        dp[i][j] = max(dp[i-1][j], x);
                    }
                    else dp[i][j] = dp[i-1][j];
                }
                else {
                    if(matrix[i][j] == '1') {
                        int ts = -1;
                        for(int z = i; z >= 0; --z) {
                            if(matrix[z][j] == '0') break;
                            int x = i - z + 1, t = x;
                            for(int k = j - 1; k >= 0; --k) {
                                int c = 0;
                                for(int s = i; s >= z; --s) {
                                    if(matrix[s][k] == '0') {
                                        c = 1;
                                        break;
                                    }
                                }
                                if(c == 1) break;
                                t += x;
                            }
                            ts = max(ts, t);
                        }
                        dp[i][j] = max(dp[i][j-1], max(dp[i-1][j], ts));
                    }
                    else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};