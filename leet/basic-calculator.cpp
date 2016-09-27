class Solution {
public:
    int calculate(string s) {
        s += " ";
        stack<int> st;
        stack<char> st_c;
        string number;
        for(int i = 0; i < s.length(); ++i) {
            int temp = 0;
            if(s[i] == ' ') {
                if(number.size() > 0) {
                    temp = stoi(number);
                    number = "";
                    if(!st_c.empty() && st_c.top() != '(') {
                        if(st_c.top() == '+')
                            st.top() += temp;
                        else if(st_c.top() == '-')
                            st.top() -= temp;
                        st_c.pop();
                    }
                    else st.push(temp);
                }
            }
            if(s[i] >= '0' && s[i] <= '9') {
                number += s[i];
            }
            else if(s[i] == '(') {
                st_c.push('(');
            }
            else if(s[i] == '+') {
                if(number.size() > 0) {
                    temp = stoi(number);
                    number = "";
                    if(!st_c.empty() && st_c.top() != '(') {
                        if(st_c.top() == '+')
                            st.top() += temp;
                        else if(st_c.top() == '-')
                            st.top() -= temp;
                        st_c.pop();
                    }
                    else st.push(temp);
                }
                st_c.push('+');
            }
            else if(s[i] == '-') {
                if(number.size() > 0) {
                    temp = stoi(number);
                    number = "";
                    if(!st_c.empty() && st_c.top() != '(') {
                        if(st_c.top() == '+') 
                            st.top() += temp;
                        else if(st_c.top() == '-')
                            st.top() -= temp;
                        st_c.pop();
                    }
                    else st.push(temp);
                }
                st_c.push('-');
            }
            else if(s[i] ==')') {
                if(number.size() > 0) {
                    temp = stoi(number);
                    number = "";
                    if(!st_c.empty() && st_c.top() != '(') {
                        if(st_c.top() == '+')
                            st.top() += temp;
                        else if(st_c.top() == '-')
                            st.top() -= temp;
                        st_c.pop();
                    }
                    else st.push(temp);
                }
                st_c.pop();
                if(!st_c.empty()) {
                    if(st_c.top() == '+') {
                        if(st.size() >= 2) {
                            int x = st.top(); st.pop();
                            st.top() += x;
                        }
                    }
                    else if(st_c.top() == '-') {
                        int x = st.top(); st.pop();
                        st.top() -= x;
                    }
                    st_c.pop();
                }
            }
        }
        return st.top();
    }
};