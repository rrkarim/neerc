/**
    Rasul Kerimov (CoderINusE)
    Burrito King
*/
#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 2e18
#define _INF -20000000
#define RANDOM_INIT()   srand(time(NULL))
#define RANDOM(L, R)    (L + rand() % ((R) - (L) + 1)) // gen a random integer in [L, R]

typedef long long ll;
using namespace std;
ll n;
double A, B, sumA, sumB, initA, initB;
int g, a, b;

struct p {
    int g, a, b, index;
    double w;
    p() {}
    p(int g, int a, int b, double w, int index) : g(g), a(a), b(b), w(w), index(index) {}
    bool operator<(p & right) {
        return this->w < right.w;
    }
    friend ostream& operator<<(ostream& s, const p& temp) {
        s << temp.g << " " << temp.a << " " << temp.b;
    }
};

vector<p> q;
vector <double> ans;

int main() {

    cin >> n >> A >> B; initA = A, initB = B;
    for(int i = 0; i < n; ++i) {
        scanf("%d%d%d", &g, &a, &b);
        if(a == 0) {
            q.push_back({g,a,b,INF,i});
            continue;
        }
        q.push_back({g,a,b,b/(double)a,i});
    }

    sort(q.begin(), q.end());
    ans.resize(n + 1);

    for(int i = 0; i < n; ++i) {
        double g = min((double)q[i].g, B / (double)q[i].b);
        ans[q[i].index] = fabs(g);
        A -= g * q[i].a, B -= g * q[i].b;
    }

    if(A > 0) {
        printf("-1 -1\n");
        return 0;
    }

    cout << fixed << setprecision(8) << initA - A << " " << initB - B << endl;
    for(int i = 0; i < n; ++i) {
        if(i) cout << " ";
        cout << fixed << setprecision(8) << ans[i];
    }
    cout << endl;

}
