/*
    Wildcard Matching
    O(n*m)
*/
class Solution {
public:
    bool match(char x, char y) {
        if((x == y) || (y == '?')) return true;
        return false;
    }
    char f(int n, int m, vector<vector<char>> &dp, const string &s, const string &p) {
        if(n < 0 || m < 0) return '0';
        if(dp[n][m] != '-') return dp[n][m];
        if(n == 0 && m == 0) return dp[n][m] = '1';
        if(p[p.size() - m] == '*' && m > 0) {
            char r = '0';
            r = f(n-1, m, dp, s, p);
            if(r == '1') return dp[n][m] = r;
            r = f(n,m-1, dp, s, p);
            return dp[n][m] = r;
        }
        else {
            if(n == 0 || m == 0) return dp[n][m] = '0';
            if(match(s[s.size()-n], p[p.size()-m])) return dp[n][m] = f(n-1,m-1,dp,s,p);
            return dp[n][m] = '0';
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<char>> dp(n+1);
        for(int i = 0; i <= n; ++i) dp[i].resize(m+1);
        for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = '-';
        f(n, m, dp, s, p);
        return (dp[n][m]=='1'?1:0);
    }
};