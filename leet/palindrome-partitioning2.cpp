/*
    Palindrome Partitioning II
*/
class Solution {
public:
    int minCut(string s) {
        int dp[s.size()+1];
        bool is_pal[s.size()+1][s.size()+1]; memset(is_pal, 0, sizeof is_pal);
        dp[0] = 0, dp[1] = 1;
        is_pal[1][1] = 1;
        for(int i = 2; i <= s.size(); ++i) {
            dp[i] = i;
            for(int j = 1; j <= i; ++j) {
                if(s[i-1] == s[j-1] && (i - j <= 1 || is_pal[j+1][i-1] == 1)) {
                    is_pal[j][i] = 1;
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[s.size()]-1;
    }
};