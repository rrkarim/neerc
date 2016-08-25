#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    int n, b, d, t, sum = 0, r = 0; cin >> n >> b >> d;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t > b) continue;
        sum += t;
        if(sum > d) r += 1, sum = 0;
    }
    cout << r << endl;
}