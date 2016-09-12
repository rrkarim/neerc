/*
    Expression Add Operators
*/
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