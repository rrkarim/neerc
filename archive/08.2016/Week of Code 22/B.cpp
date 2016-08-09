#include <bits/stdc++.h>
#define MAX_CHAR 256
#define MAXN 200005
#define INF 1000000
using namespace std;

typedef long long ll;
int n;
vector<int> a;
int sum = 0, x, res = 0;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a.push_back(x);
        sum += a[i];
    }
    while(true) {
        sort(a.begin(), a.end());
        int x = a[a.size() - 1];
        sum -= x;
        if(x < sum) break;
        sum += x;
        if(x % 2 == 0) {
            a[a.size() - 1] = x / 2;
            a.push_back(x / 2);
        }
        else {
            a[a.size() - 1] = x / 2;
            a.push_back(x / 2 + 1);
        }
        res += 1;
    }
    cout << res << endl;
}
