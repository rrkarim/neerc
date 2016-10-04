class Solution {
public:
    int dp[300][300];
    void f(int index, int index_l, vector<vector<string>> &ans, vector<string> temp, const string &s) {
        if(index == s.size() && temp.size() > 0 && index == index_l) {
            ans.push_back(temp);
            return;
        }
        if(dp[index_l][index]) {
            temp.push_back(s.substr(index_l, index - index_l + 1));
            f(index+1,index+1, ans, temp, s);
            temp.pop_back();
        }
        f(index + 1, index_l, ans, temp, s);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if(s.size() == 0) return ret;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i < s.size(); ++i) {
            for(int j = 0; j <= i; ++j) {
                if(s[i] == s[j] && (i - j <= 1 || dp[j+1][i-1] == 1)) {
                    dp[j][i] = 1;
                }
            }
        }
        vector<string> temp;
        f(0, 0, ret, temp, s);
        return ret;
    }
};