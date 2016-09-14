class Solution {
    public:
    bool match(char x, char y) {
        if((x == y) || (y == '.')) return true;
        return false;
    }
    bool f(int n, int m, vector<vector<int>> &dp, const string &s, const string &p) {
        if(dp[n][m] != -1) return dp[n][m];
        if(n == 0 && m == 0) return true;
        if(m != 1 && p[p.size() - m+1] == '*') {
            bool r = false;
            if(n > 0 && match(s[s.size()-n], p[p.size()-m])) r = f(n-1, m, dp, s, p);
            if(r == true) return dp[n][m] = true;
            r = f(n, m-2, dp, s, p);
            return dp[n][m] = r;
        }
        else {
            if(n == 0 || m == 0) return false;
            if(match(s[s.size()-n], p[p.size()-m])) return f(n-1,m-1,dp,s,p);
            return false;
        }
    }
    bool isMatch(string s, string p) {
    	int n = s.size();
    	int m = p.size();
    	vector<vector<int>> dp(n+1);
    	for(int i = 0; i <= n; ++i) dp[i].resize(m+1);
    	for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = -1;
    	return f(n, m, dp, s, p);
    }
};