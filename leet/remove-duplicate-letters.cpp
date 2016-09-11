class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        int c[50], u[s.size() + 2];
        memset(c, 0, sizeof c);
        memset(u, 0, sizeof u);
        for(int i = 0; i < s.length(); ++i) c[s[i] - 'a'] += 1;
        int i = 0;
        while(true) {
            if(i == s.length()) break;
            if(u[i] == 1) { i += 1; continue; }
            if(c[s[i] - 'a'] == 1) {
                res += s[i];
                c[s[i]-'a'] -= 1;
                i += 1;
                continue;
            }
            char maxchar = s[i];
            int index = i, cx[50]; memset(cx, 0, sizeof cx);
            for(int j = 0; j < 40; ++j) cx[j] = c[j];
            for(int j = i; j < s.size(); ++j) {
                if(u[j]) continue;
                if(s[j] < maxchar) {
                    maxchar = s[j];
                    index = j;
                }
                if(cx[s[j] - 'a'] == 1) {
                    break;
                }
                cx[s[j] - 'a'] -= 1;
            }
            res += maxchar;
            for(int j = i; j <= index; ++j) c[s[j]-'a'] -= 1;
            i = index + 1;
            for(int j = i; j < s.size(); ++j) if(s[j] == maxchar) u[j] = 1;
        }
        return res;
    }
};