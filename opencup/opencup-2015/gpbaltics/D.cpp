#include <bits/stdc++.h>
#define MAXN 100003
#define INF 1000000000
//#define first x
//#define second y
using namespace std;
typedef long long ll;
ll mod = 1000000007;

//set <int> S[10];
int n;
ll x[MAXN + 2], y[MAXN + 2];
struct triangle {
    ll a, b, c;
    int left = 0;
    triangle() {}
    triangle(ll _a, ll _b, ll _c) {
        if(_a >= _b && _a >= _c) {
            a = _a;
            ll sum = 0;
            if(_b < _c) {
                sum += (x[0] - x[2])*(y[0] + y[2]);
                sum += (x[1] - x[0])*(y[1] + y[0]);
                sum += (x[2] - x[1])*(y[2] + y[1]);
            }
            else {
                sum += (x[1] - x[2])*(y[1] + y[2]);
                sum += (x[0] - x[1])*(y[0] + y[1]);
                sum += (x[2] - x[0])*(y[2] + y[0]);
            }
            if(sum < 0) left = 1;
            b = max(_b, _c);
            c = min(_b, _c);
        }
        else if(_b >= _c && _b >= _a) {
            a = _b;

            ll sum = 0;
            if(_a < _c) {
                sum += (x[0] - x[1])*(y[0] + y[1]);
                sum += (x[2] - x[0])*(y[2] + y[0]);
                sum += (x[1] - x[2])*(y[1] + y[2]);
            }
            else {
                sum += (x[2] - x[1])*(y[2] + y[1]);
                sum += (x[0] - x[2])*(y[0] + y[2]);
                sum += (x[1] - x[0])*(y[1] + y[0]);
            }
            if(sum < 0) left = 1;
            b = max(_a, _c);
            c = min(_a, _c);
        }
        else {
            a = _c;

            ll sum = 0;
            if(_a < _b) {
                sum += (x[1] - x[0])*(y[1] + y[0]);
                sum += (x[2] - x[1])*(y[2] + y[1]);
                sum += (x[0] - x[2])*(y[0] + y[2]);
            }
            else {
                sum += (x[2] - x[0])*(y[2] + y[0]);
                sum += (x[1] - x[2])*(y[1] + y[2]);
                sum += (x[0] - x[1])*(y[0] + y[1]);
            }
            if(sum < 0) left = 1;

            b = max(_a, _b);
            c = min(_a, _b);
        }
    }
    bool operator<(const triangle &second) const {
        return (a == second.a ? ( b == second.b ? (c == second.c ? left < second.left : c < second.c) : (b < second.b) ) : a < second.a);
    }
};
map < triangle, vector<int> > M;
vector < pair <int, int> > res;
int used[MAXN + 2], used_size = 0;
int main() {
    //ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld%lld%lld%lld", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        ll a = 1LL * ( (x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]) ) ,
        b = 1LL * ( (x[0] - x[2])*(x[0] - x[2]) + (y[0] - y[2])*(y[0] - y[2]) ),
        c = 1LL * ( (x[2] - x[1])*(x[2] - x[1]) + (y[2] - y[1])*(y[2] - y[1]) );


        triangle sample_triangle = triangle(a, b, c);
        sample_triangle.left = sample_triangle.left == 0 ? 1 : 0;

        if(M[sample_triangle].size()) {
            res.push_back({i + 1, M[sample_triangle].back()});
            used[i + 1] = used[M[sample_triangle].back()] |= 1;
            M[sample_triangle].pop_back();
            used_size += 2;
            continue;
        }

        sample_triangle.left = sample_triangle.left == 0 ? 1 : 0;

        if(sample_triangle.b == sample_triangle.c && M[sample_triangle].size()) {
            res.push_back({i + 1, M[sample_triangle].back()});
            used[i + 1] = used[M[sample_triangle].back()] |= 1;
            M[sample_triangle].pop_back();
            used_size += 2;
            continue;
        }

        M[sample_triangle].push_back(i + 1);
    }

    printf("%d\n", res.size() + n - used_size);
    for(int i = 0; i < res.size(); ++i) {
        printf("%d-%d\n", res[i].first, res[i].second);
    }
    for(int i = 1; i <= n; ++i ) {
        if(!used[i]) {
            printf("%d-0\n", i);
        }
    }
}
