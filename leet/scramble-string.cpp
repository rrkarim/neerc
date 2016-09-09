class Solution {
public:
    bool check_arr(int a1[], int a2[]) {
        for(int i = 0; i < 80; ++i) if(a2[i] != a1[i]) return false;
        return true;
    } 
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        if(s1.length() == 0 || s1 == s2) return true;
        
        int c1[80]; memset(c1, 0, sizeof c1);
        for(int i = 0; i < s1.size(); ++i) c1[s1[i] - 'A'] += 1;
        int x1[80]; memset(x1, 0, sizeof x1);
        for(int i = 0; i < s1.size(); ++i) x1[s2[i] - 'A'] += 1;
        if(!check_arr(c1, x1)) return false;
        
        for(int i = 1; i < s1.length(); ++i) {
            string s11 = s1.substr(0, i),
            s12 = s1.substr(i, s1.length() - i),
            s21 = s2.substr(0, i),
            s22 = s2.substr(i, s1.length() - i),
            s23 = s2.substr(0, s1.length() - i),
            s24 = s2.substr(s1.length() - i, i);
            if((isScramble(s11, s21) && isScramble(s12, s22)) || isScramble(s11, s24) && isScramble(s12, s23)) return true;
        }
        return false;
    }
};
/**
*/
class Solution {
public:
    
    bool check_arr(int a1[], int a2[], int x1[], int x2[]) {
        for(int i = 0; i < 80; ++i) if(x1[i] != a1[i]) return false;
        for(int i = 0; i < 80; ++i) if(x2[i] != a2[i]) return false;
        return true;
    }
    
    bool check(string a, string b, int l, int r) {
        if(r == l) {
            if(a[l] != b[l]) return false;
            return true;
        }
        int s1 = (r - l + 1) / 2, s2 = (r - l + 2) / 2;
        int c1[80], c2[80]; memset(c1, 0, sizeof c1); memset(c2, 0, sizeof c2);
        for(int i = l; i < l + s1; ++i) c1[a[i] - 'A'] += 1;
        for(int i = l + s1; i < l + s2 + s1; ++i) c2[a[i] - 'A'] += 1;
        // left-right
        int x1[80], x2[80]; memset(x1, 0, sizeof x1); memset(x2, 0, sizeof x2);
        
        for(int i = l; i < l + s1; ++i) x1[b[i] - 'A'] += 1;
        for(int i = l + s1; i < l + s1 + s2; ++i) x2[b[i] - 'A'] += 1;
        
        bool rs = check_arr(c1, c2, x1, x2);
        cout << rs << endl;
        if(rs == true) {
            bool t1 = check(a, b, l, l + s1 - 1), t2 = check(a, b, l + s1, r);
            if(t1 && t2) return true;
        }
        //right-left
        memset(x1, 0, sizeof x1); memset(x2, 0, sizeof x2);
        for(int i = r; i > r - s1; --i) x1[b[i] - 'A'] += 1;
        for(int i = l; i < l + s2; ++i) x2[b[i] - 'A'] += 1;
        
        rs = check_arr(c1, c2, x1, x2);
        cout << rs << endl;
        if(rs == true) {
            string temp = b.substr(s1, s2) + b.substr(0, s1);   
            bool t1 = check(a, temp, l, l + s1 - 1), t2 = check(a, temp, l + s1, r);
            if(t1 && t2) return true;
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        
        return check(s1, s2, 0, s1.length() - 1);
        
    }
};