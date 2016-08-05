#include <bits/stdc++.h>
#define MAX_CHAR 256
#define INF 1000000000000
#define MAXN 100000
using namespace std;
typedef long long ll;
ll n, x, res;
int main() {
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n / 2; ++i) {
        if(n % i == 0) {
            for(int j = 1; j <= n / i; ++j) {
                ll sum = 0, x = i;
                if(j == 1) res += 1;
                else {
                    while(sum < n) {
                        sum += x;
                        x *= j;
                    }
                    if(sum == n) res += 1;
                }
            }
        }
    }
    cout << res << endl;
}
