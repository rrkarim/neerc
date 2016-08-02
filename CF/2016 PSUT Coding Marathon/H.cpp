/**
*/
#include <bits/stdc++.h>
#define MAXN 100005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;
int ks[10], a[MAXN + 2][10], used[10];
int x[10] = {1, 5, 10, 20, 50}, n;
int main() {
    /**
    //freopen("bonus.in", "r", stdin);
    //freopen("bonus.out", "w", stdout);
    */
    cin >> n;
    for(int i = 0; i < n; ++i) {
        scanf("%d", ks + i);
        for(int j = 0; j < 5; ++j) scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; ++i) {
        int sum = 0, k = ks[i];
        for(int j = 0; j < 5; ++j) {
            sum += a[i][j] * x[j];
        }
        sum = sum - k;
        for(int j = 0; j < 5; ++j) used[j] += a[i][j];

        for(int j = 4; j >= 0; --j) {
            if(sum >= x[j]) {
                sum -= min(used[j], (sum / x[j])) * x[j];
                used[j] -= min(used[j], (sum / x[j]));
            }
        }
        if(sum) {
            cout << "no" << endl;
            exit(0);
        }


    }
    cout << "yes" << endl;

}
