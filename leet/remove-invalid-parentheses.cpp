class Solution {
public:
    int maxn = 1000000;
    vector <string> vi;
    map <string, int> u;
    void f(string s, string r, int ans, int l) {
        if(s.empty()) {
            if(l == 0) {
                reverse(r.begin(), r.end());
                if(ans < maxn) {
                    if(!u[r]) {
                        vi.clear();
                        maxn = ans;
                        vi.push_back(r), u[r] = 1;
                    }
                }
                else if(ans == maxn) {
                    if(!u[r]) {
                        vi.push_back(r), u[r] = 1;
                    }
                }
            }
            return;
        }
        if(s[s.length() - 1] == '(') {
            s.erase(s.end()-1);
            f(s, r, ans + 1, l);
            if(l) {
                r.push_back('(');
                f(s, r, ans, l - 1);
            }
        }
        else if(s[s.length()-1] == ')') {
            s.erase(s.end()-1);
            f(s, r, ans + 1, l);
            r.push_back(')');
            f(s, r, ans, l + 1);
        }
        else {
            r.push_back(s[s.length() - 1]);
            s.erase(s.end()-1);
            f(s, r, ans, l);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        f(s, "", 0, 0);
        return vi;
    }
};