#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 1000005
#define INF 1000000
using namespace std;

typedef long long ll;
ll d[20], sum_[20], x[20];
ll n;


void _init_() {
    d[1] = 1, sum_[1] = 1, x[1] = 10, x[0] = 1;
    ll t = 1;
    for(int i = 2; i <= 18; ++i) {
        d[i] = (9 * i + 1) * t;
        t *= 10;
        x[i] = t * 10;
        sum_[i] = sum_[i - 1] + d[i];
    }
}
string solve(ll n) {
    vector <int> res;
    ll sum = 0;
    int len = -1;
    for(int i = 1; i <= n; ++i) {
        sum += d[i];
        if(sum >= n) {
            len = i;
            break;
        }
    }
    ll z = 0;
    for(int i = 0; i < len; ++i) {
        ll sum_t = 0, pre_t = 0;
        for(int j = 0; j <= 9; ++j) {
            if(j == 1) {
                sum_t += sum_[len - i - 1] + x[len - i - 1] + z * x[len - i - 1] ;
            }
            else {
               sum_t += sum_[len - i - 1] + z * x[len - i - 1];
            }
            if(sum_t >= n) {
                n -= pre_t;
                res.push_back(j);

                if(j == 1) z += 1;
                break;
            }
            pre_t = sum_t;
        }
    }
    string r;
    for(int i = 0; i < res.size(); ++i) r += ('0' + res[i]);
    return r;
}

int main() {
    ll n; cin >> n;

    _init_();

    string a = solve(n), b = solve(n + 1);
    if(a == b) {
        cout << "Petr lies" << endl;
    }
    else cout << a << endl;


}
