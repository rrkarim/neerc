/*
	Longest Valid Parentheses-
*/
class Solution {
    public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>> st;
        int maxn = 0, curr = 0, dp[s.size()+2]; fill(dp,dp+s.size(),0);
        if(s.size() == 0) return maxn;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ')') {
                if(st.size() == 0) {
                    maxn = max(curr, maxn);
                    curr = 0;
                }
                else {
                    int x = st.top().second;
                    if(x == 0) dp[i] = i - x + 1;
                    else {
                        dp[i] = dp[x-1] + i - x + 1;
                    }
                    st.pop();
                    maxn = max(curr, maxn);
                }
            }
            else {
                st.push({'(',i});
            }
        }
        int res = 0;
        for(int i = 0; i < s.size(); ++i) res = max(res, dp[i]);
        return res;
    }
};