/*
    Minimum Window Substring
*/
class Solution {
public:
     string minWindow(string s, string t) {
        string rs;
        if(t.size()==0) return rs;
        int l = 0, r = 1, x = 0, count[70]; memset(count, 0, sizeof count);
        for(int i = 0; i < t.size(); ++i) count[t[i]-'A'] -= 1;
        string ans = "?";
        for(int j = 0; j < s.size(); ++j) {
            rs += s[j];
            count[s[j]-'A'] += 1;
            int c = 0;
            for(int i = 0; i < 70; ++i) {
                if(count[i] < 0) {
                    c = 1;
                    break;
                }
            }
            if(c == 0) {
                int z = 0;
                for(z = 0; z < rs.size(); ++z) {
                    if(count[rs[z]-'A'] >= 1) count[rs[z]-'A'] -= 1;
                    else break;
                }
                rs = rs.substr(z);
                if(ans == "?") ans = rs;
                else if(rs.size() < ans.size()) ans = rs;
            }
            else {
                int z;
                for(z = 0; z < rs.size(); ++z) {
                    if(count[rs[z]-'A'] >= 1) count[rs[z]-'A'] -= 1;
                    else break;
                }
                rs = rs.substr(z);
            }
        }
        if(ans == "?") return "";
        return ans;
    }
};