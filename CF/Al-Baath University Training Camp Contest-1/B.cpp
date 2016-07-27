/**
*/
#include <bits/stdc++.h>
#define MAXN 50005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
int n, m, x, y, c, r;
string a, b;

bool check(string a, string b) {
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i] && abs((int)(a[i] - b[i])) != 32) {
            if(a[i] == 'p' || a[i] == 'P') {
                if(b[i] != 'b' && b[i] != 'B') return 0;
            }
            else if(a[i] == 'i' || a[i] == 'I') {
                if(b[i] != 'e' && b[i] != 'E') return 0;
            }
            else if(a[i] == 'b' || a[i] == 'B') {
                if(b[i] != 'P' && b[i] != 'p') return 0;
            }
            else if(a[i] == 'e' || a[i] == 'E') {
                if(b[i] != 'i' && b[i] != 'I') return 0;
            }
            else return 0;
        }
    }
    return 1;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> a >> b;
        if(a.size() != b.size() || !check(a, b)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
