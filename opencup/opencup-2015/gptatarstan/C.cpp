/**
    Rasul Kerimov (CoderINusE)
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

const ll mod = 1e9 + 9ll;
double ans = 1.0;

string s1, s2, t[15];

int check(string s, char c) {
    int res = 0;
    if(s[0] == c || s[1] == c || s[3] == c || s[5] == c) res += 1;
    if(s[1] == c || s[2] == c || s[3] == c || s[4] == c) res += 1;
    return res;
}

int main() {
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); ++i) {
        cin >> t[i];
    }
    for(int i = 0; i < s1.length(); ++i) {
        if(s1[i] != s2[i]) {

            int c = check(t[i], s2[i]);
            if(c == 1) ans /= 2.0;
            else if(c == 0) ans = 0.0;

        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
