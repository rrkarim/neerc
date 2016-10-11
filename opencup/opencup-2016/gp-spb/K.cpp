#include <bits/stdc++.h>
#include <string>
#define MAXN 2000000
using namespace std;
typedef long long ll;

vector<char> prime (2000003, true);
map<int, int> mp;

bool check(int n) {
    if(mp[n]) return true;
    if(prime[n] == false) return false;
    int len = 0, temp = n;
    while(temp) {
        len += 1;
        temp /= 10;
    }
    int d = 1;
    for(int i = 0; i < len - 1; ++i) d *= 10;
    if(check(n / 10) && check(n % d)) {
        return true;
    }
    return false;
}

int main() {
    freopen("ultraprime.in", "r", stdin);
    freopen("ultraprime.out", "w", stdout);
    int x; cin >> x;
    int n = 2000000;
    if(x >= 10) {
        cout << -1 << endl;
        return 0;
    }
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
    mp[2] = mp[3] = mp[5] = mp[7] = 1;
    int s = 0;
    for(int i = 2; i <= 2000000;++i) {
        if(prime[i] == false) continue;
        if(mp[i] == 1) {
            s += 1;
            if(s == x) {
                cout << i << endl;
                break;
            }
            continue;
        }
        else {
            if(check(i)) {
                mp[i] = 1;
                s += 1;
            }
            if(s == x) {
                cout << i << endl;
                break;
            }
        }
    }
}

