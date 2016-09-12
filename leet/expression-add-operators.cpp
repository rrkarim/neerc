/*
    Expression Add Operators
*/

class Solution {
public:
    vector <string> res;
    void f(int index, string st, long temp, const long &target, const string &num, long pre, char pre_c) {
        if(index == num.size() && temp == target) {
            res.push_back(st);
        }
        else {
            for(int i = index + 1; i <= num.size(); ++i) {
                string t = num.substr(index, i - index);
                long x = stol(t);
                if(to_string(x).size() != t.size()) continue;
                f(i, st+"+"+t, temp+x, target, num, x, '+');
                f(i, st+"-"+t, temp-x, target, num, x, '-');
                f(i, st+"*"+t, (pre_c == '+' ? temp-pre + pre*x : ((pre_c=='-'?temp+pre-pre*x:pre*x))), target, num, pre*x, pre_c);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        if(num.size() == 0) return res;
        string temp; temp += num[0];
        for(int i = 1; i <= num.size(); ++i) {
            string s = num.substr(0, i);
            long cur = stol(s);
            if (to_string(cur).size() != s.size()) continue;
            f(i, s, cur, target, num, cur, '#');
        }
        return res;
    }
};

class Solution {
public:
    vector <string> res;
    void f(int index, int n, string st, int temp, int target, string num, int pre, char pre_c) {
        if(index == n) {
            if(temp == target) res.push_back(st); 
            return;
        }
        else {
            int temps = temp, pres, ds = temp;
            if(pre_c != 'u') {
                if(pre == 0) {
                    temp = 0;
                    temps = 0;
                }
                else {
                    if(pre_c == '+') temp -= pre;
                    else if(pre_c == '-') temp += pre;
                    else temp /= pre;
                    if(pre_c == '+') temps -= pre;
                    else if(pre_c == '-') temps += pre;
                    else temps *= pre;
                    pres = 10 * pre + (num[index] - '0');
                    pre *= (num[index]-'0');
                    if(pre_c == '+') temp += pre;
                    else if(pre_c == '-') temp -= pre;
                    else temp *= pre;
                    if(pre_c == '+') temps += pres;
                    else if(pre_c == '-') temps -= pres;
                    else temps *= pres;
                }
            }
            else {
                temp *= (num[index]-'0');
                pres = 10 * pre + (num[index] - '0');
                temps = pres;
            }
            f(index + 1, n, st+"*"+num[index], temp, target, num, num[index]-'0', '*');
            f(index + 1, n, st+num[index], temps, target, num, pres, pre_c);
            f(index + 1, n, st+"+"+num[index], ds+(num[index]-'0'), target, num, num[index]-'0', '+');
            f(index + 1, n, st+"-"+num[index], ds-(num[index]-'0'), target, num, num[index]-'0', '-');
        }
    }
    vector<string> addOperators(string num, int target) {
        if(num.size() == 0) return res;
        string temp; temp += num[0];
        f(1, num.size(), temp, (int)(num[0] - '0'), target, num, (num[0]-'0'), 'u');
        return res;
    }
};