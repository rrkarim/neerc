#include <bits/stdc++.h>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 200004

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;

vector <vector <int>> g;
int u, v;

double ans;

void dfs(int v, int p, double x, int distance = 0) {
    if(g[v].size() == 1 && v != 1) {
        ans += x * distance;
        return;
    }
    else if(g[v].size() == 0 && v == 1) {
        ans += x * distance;
        return;
    }

    double x_;
    if(v != 1) x_ = 1. / (double) (g[v].size() - 1);
    else x_ = 1. / (double) (g[v].size());

    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(to != p) dfs(to, v, x * x_, distance + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    g.resize(n + 2);
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, -1, 1.);
    cout << fixed << setprecision(7) << ans << endl;

}