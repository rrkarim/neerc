/**
    Rasul Kerimov (CoderINusE)
    Froggy Ford
*/
#include <bits/stdc++.h>
#define MAXN 1000
#define INF 20000000000
#define _INF -20000000
#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;

typedef pair<ll, ll> pi;

ll w, x, y;
int n;
vector <double> minimaxl, minimaxr;
vector <pi> g;

double dist(const pi &a, const pi &b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

pair <double, double> find_point(const int &i, const int &j) {
    if(i == 0 && j == 0) return {(double) w / 2.0, 1.0 };
    else if(i == 0) return { (double)g[j].first / 2.0 , (double)g[j].second };
    else if(j == n + 1) return { (double)(w + g[i].first) / 2.0, (double)g[i].second };
    else return { (double)fabs(g[i].first + g[j].first) / 2.0, (double)fabs(g[i].second + g[j].second) / 2.0 };
}

void dijkstra_left() {
    minimaxl.resize(MAXN + 1, (double)INF);
    minimaxl[0] = .0;
    vector<char> u(MAXN + 1);
    for(int i = 0; i <= n + 1; ++i) {
        int v = -1;
        for(int j = 0; j <= n + 1; ++j)
            if(!u[j] && (v == -1 || minimaxl[j] < minimaxl[v]))
                v = j;

        if(minimaxl[v] == INF) break;
        u[v] = true;

        if(v == n + 1) continue;

        for(int j = 1; j <= n + 1; ++j) {
            if(j == v) continue;
            double len = .0;
            if(v == 0) {
                len = (double)g[j].first;
                if(j == n + 1) len = (double)w;
            }
            else if(j == n + 1) len = (double)(w - g[v].first);

            else len = dist(g[v], g[j]);

            len = max(minimaxl[v], len);
            if(len < minimaxl[j]) {
                minimaxl[j] = len;
            }
        }
    }
}

void dijkstra_right() {
    minimaxr.resize(MAXN + 1, (double)INF);
    minimaxr[n + 1] = .0;
    vector<char> u(MAXN + 1);
    for(int i = 0; i <= n + 1; ++i) {
        int v = -1;
        for(int j = 0; j <= n + 1; ++j)
            if(!u[j] && (v == -1 || minimaxr[j] < minimaxr[v]))
                v = j;

        if(minimaxr[v] == INF) break;
        u[v] = true;

        if(v == 0) continue;

        for(int j = 0; j <= n; ++j) {
            if(j == v) continue;
            double len = .0;
            if(v == n + 1) {
                len = (double)(w - g[j].first);
                if(j == 0) len = (double)w;
            }
            else if(j == 0) len = (double)(g[v].first);

            else len = dist(g[v], g[j]);

            len = max(minimaxr[v], len);
            if(len < minimaxr[j]) {
                minimaxr[j] = len;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> w >> n;
    g.push_back({0, 0});
    for(int i = 1; i <= n; ++i) {
        cin >> x >> y;
        g.push_back({x,y});
    }
    dijkstra_left();
    dijkstra_right();

    double ans = INF;
    pair <double, double> ann;
    int in, jn;

    for(int i = 0; i <= n + 1; ++i) {

        for(int j = 0; j <= n + 1; ++j) {

            if(i == j) continue;

            double  left = (i == 0 ? .0 : minimaxl[i]),
                    right = (j == n + 1 ? .0 : minimaxr[j]);

            double mdist = 0.0;
            if(i == 0 && j == n + 1) mdist = (double)w / 2.0;
            else if(i == 0) mdist = (double)g[j].first / 2.0;
            else if(j == n + 1) mdist = (double) (w - g[i].first) / 2.0;
            else mdist = dist(g[i], g[j]) / 2.0;

            double dist = max(left, max(right, mdist));

            if(dist < ans) {

                ans = dist;
                ann = find_point(i, j);
            }

        }

    }

    //cout << ans << endl;
    cout << fixed << setprecision(3) << ann.first << " " << ann.second << endl;

}
