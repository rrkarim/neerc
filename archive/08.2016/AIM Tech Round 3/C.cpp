#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
int x[MAXN + 2];
vector <int> am, bm;
int main() {
    string s;
    cin >> s;
    int l = 0, r;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'a') l += 1;
        else break;
    }
    r = l + 1;
    for(int i = l + 1; i < s.length(); ++i) {
        if(s[i] == 'a') break;
        else r += 1;
    }
    for(int i = l; i < r; ++i) {
        s[i] -= 1;
    }
    if(l == s.length()) {
        s[s.length() - 1] = 'z';
        cout << s << endl;
    }
    else cout << s << endl;

}