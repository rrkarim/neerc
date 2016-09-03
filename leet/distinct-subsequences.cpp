class Solution {
public:
    int numDistinct(string s, string t) {
        swap(s, t);
        if(s.size() == 0 || t.size() == 0) return 0;
        int dp[s.size() + 1][t.size() + 1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i <= t.size(); ++i) dp[0][i] = 1;
        
        for(int i = 1; i <= s.length(); ++i) {
            
            for(int j = i; j <= t.size(); ++j) {
                
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i][j - 1] + dp[i - 1][j - 1];
                }    
                else {
                    dp[i][j] += dp[i][j - 1];
                }
            }
            
        }
        return dp[s.size()][t.size()];
    }
};