#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 9ll;
double ans = 1.0;

string s1, s2, t, no = "-";

int check(string s, char c) {
    int res = 0;
    if(s[0] == c || s[1] == c || s[3] == c || s[5] == c) res += 1;
    if(s[0] == c || s[2] == c || s[4] == c || s[5] == c) res += 1;
    return res;
}
string str(const string& s, int n) {
    string t = s;
    if(n == 1)
        t[0] = s[1], t[1] = s[5], t[2] = s[2], t[3] = s[0],t[4] = s[4], t[5] = s[3];
    else if(n == 2)
        t[0] = s[2], t[1] = s[1], t[2] = s[5], t[3] = s[3],t[4] = s[0], t[5] = s[4];
    else if(n == 3)
        t[0] = s[3], t[1] = s[0], t[2] = s[2], t[3] = s[5], t[4] = s[4], t[5] = s[1];
    else if(n == 4)
        t[0] = s[4], t[1] = s[1], t[2] = s[0], t[3] = s[3], t[4] = s[5], t[5] = s[2];
    else if(n == 5)
        t[0] = s[5], t[1] = s[1], t[2] = s[4], t[3] = s[3], t[4] = s[2], t[5] = s[0];
    return t;
}
int main() {
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); ++i) {
        cin >> t;
        vector<int> vi;
        for(int j = 0; j < t.length(); ++j)
            if(t[j] == s1[i]) vi.push_back(j);
        if(s1[i] != s2[i]) {
            double p = 0.0;
            for(int j = 0; j < vi.size(); ++j) {
                string x = str(t, vi[j]);
                int c = check(x, s2[i]);

                if(c == 2)
                    p += 1.0 / (double) vi.size();
                else if(c == 1)
                    p += 1.0 / (2.0 * (double) vi.size());
            }
            ans *= p;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
