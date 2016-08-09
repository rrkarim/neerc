#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 1000000
using namespace std;

typedef long long ll;
int n, x, y;
int main() {
    int n; cin >> n;
    while(n -- ) {
        cin >> x >> y;
        int c = !(x & 1)+!(y & 1);
        if(c >= 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
