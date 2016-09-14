/*
    Interleaving String
    O(n*m)
*/
class Solution {
public:
    bool f(int n, int m, vector<vector<int>> &dp, const string& s1, const string& s2, const string& s3) {
        if(n == 0 && m == 0) return true;
        if(dp[n][m] != -1) return dp[n][m];
        bool r = false;
        int k = n;
        if(k > 0) {
            for(int i = s3.size() - n - m; i < s3.size(); ++i) {
                if(k == 0 || s3[i] != s1[s1.size()-k]) break;
                if(r == false) r = f(k-1, m, dp, s1, s2, s3);
                else return dp[n][m] = true;
                k -= 1;
            }
        }
        if(r == true) return dp[n][m] = true; 
        k = m;
        if(k > 0) {
            for(int i = s3.size() - n - m; i < s3.size(); ++i) {
                if(k == 0 || s3[i] != s2[s2.size()-k]) break;
                if(r == false) r = f(n, k-1, dp, s1, s2, s3);
                else return dp[n][m] = true;
                k -= 1;
            }
        }        
        return dp[n][m] = r;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int x = s3.size();
        if(n + m != x) return 0;
        vector<vector<int>> dp(n+1);
        for(int i = 0; i <= n; ++i) dp[i].resize(m+1);
        for(int i = 0;i <= n; ++i) for(int j=0;j <= m; ++j) dp[i][j] = -1;
        return f(n, m, dp, s1, s2, s3);
    }
};