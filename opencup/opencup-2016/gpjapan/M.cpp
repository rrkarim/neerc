#include <bits/stdc++.h>
#define in(x) scanf("%d" ,&x)
#define IN(x) scanf("%I64d" , &x)
#define ll long long
#define all(a) memset(a , 0 , sizeof a)
#define ull unsigned long long
#define pii pair<int , int>
using namespace std;
const ll mod = 1e9+7;
ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd ( ll a, ll b ){ll c;  while ( a != 0 ) { c = a; a = b%a;  b = c;}return b;};
ll lcm ( ll a , ll b) {return a / gcd(a , b) * b;}
bool palin(int n) {
    string res;
    while(n) {
        res += (char)('0'+n%10);
        n /= 10;
    }
    for(int i = 0; i < res.size()/2 + res.size() % 2; ++i) {
        if(res[i] != res[res.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        int x = n / 5 + (n % 5 != 0);
        n += x;
        while(true) {
            if(palin(n)) break;
            n += 1;
        }
        cout << n << endl;
    }
}

