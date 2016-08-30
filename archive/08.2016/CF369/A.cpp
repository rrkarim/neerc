#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
string s[1005];
int main() {
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int found = 0;
    for(int i = 0; i< n; ++i) {
        int f = 0;
        int c = 0;
        for(int j = 0; j < s[i].size(); ++j) {

            if(s[i][j] == '|') { f = 1, c = 0; continue; }
            if(f == 0) {
                if(s[i][j] == 'O') c += 1;
                if(c == 2) {
                    s[i][j - 1] = '+';
                    s[i][j] = '+';
                    found = 1;
                    break;
                }
            }
            else {
                if(s[i][j] == 'O') c += 1;
                if(c == 2) {
                    s[i][j - 1] = '+';
                    s[i][j] = '+';
                    found = 1;
                    break;
                }
            }
        }
        if(found == 1) break;
    }
    if(found == 0) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i) cout << s[i] << endl;
}