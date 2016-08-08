/**
    Cookie Party
*/
#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
#define INF 1000000
using namespace std;

typedef long long ll;

int main() {
    ll n, m; cin >> m >> n;
    if(n % m == 0 && n >= m) cout << 0 << endl;
    else cout << m - (n % m) << endl;
}
