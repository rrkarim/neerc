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
int main() {
    int n , m;
    cin >> n >> m;
    if(n > m) swap(n , m);
    if(n % 2 != 0) n ++;
    if(m % 2 != 0) m --;
    if(n > m) {
        cout<<0<<endl;
        return 0;
    }
    else cout<< (m - n) / 2 + 1 <<endl;
}

