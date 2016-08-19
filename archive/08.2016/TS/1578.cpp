#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
#define pi 3.14159265358979323846
using namespace std;

typedef long long ll;

pair <int, int> p[2000 + 5];
int n;

double len(int a, int b) {
    return sqrt((p[b].first-p[a].first)*(p[b].first-p[a].first)+(p[b].second-p[a].second)*(p[b].second-p[a].second));
}
bool check(int g, int p_, int c) {
    if(g == -1 || p_ == -1) return true;
    int xa = p[g].first - p[p_].first, xb = p[c].first - p[p_].first, ya = p[g].second - p[p_].second, yb = p[c].second - p[p_].second;
    double dot = xa * xb + ya * yb;
    dot /= len(g, p_);
    dot /= len(p_, c);
    double angle = acos(dot) / pi * 180.0;
    if(fabs(angle - 90.0) < 0.0000001) return false;
    if(angle < 90.0) return true;
    else return false;
}
int us[2005];
void f(int p, int c, vector <int>& r) {
    r.push_back(c); us[c] = 1;

    if(r.size() == n + 2) {
        cout << "YES" << endl;
        for(int i = 0; i < r.size(); ++i) cout << r[i] << " \n"[i == r.size() - 1];
        exit(0);
    }
    for(int i = 1; i <= n + 2; ++i) {
        if(check(p, c, i) && !us[i]) {
            f(c, i, r);
        }
    }
    r.pop_back(); us[c] = 0;
}

int main() {

    cin >> n;
    for(int i = 1; i <= n + 2; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    vector <int> temp;
    f(-1, 1, temp);
    cout << "NO" << endl;
}

