#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 100005
#define INF 10000000000000
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
double x, y;
double v[1005], xs[1005], ys[1005];

double dist(int i) {
    return sqrt( (xs[i] - x) * (xs[i] - x) + (ys[i] - y) * (ys[i] - y) );
}

int main() {
    double ans = INF;
    cin >> x >> y;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i] >> v[i];
        ans = min(ans, double(dist(i) / v[i]));
    }
    cout << fixed << setprecision(6) << ans << endl;
}