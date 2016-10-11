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
double a[111];
int l = 0;
map<double, int>::iterator it;
map<double, int>m;
map<double, int>cvb_ind;
map<double, int>ind;
struct Sol {
    double ans;
    double num;
    int dv;
};
vector<Sol> p;
bool cmp(const Sol &a , const Sol &b) {
    return a.ans < b.ans;
}
double min_diff = 111.;
int say = 0;
int main() {
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(m.count(a[i]) == 0) {
            m[a[i]] = 1;
            l ++;
            for(int j = 1; j <= k; ++ j) {
                p.push_back({a[i] / j , a[i] , j});
            }
        }
    }
    sort(p.begin(), p.end() , cmp);
    for(int i = 0; i < p.size(); ++ i) {
        double mn = 111.;
        double mx = 0.;
        if(ind.count(p[i].num) == 0)
            say ++;
        ind[p[i].num] = p[i].dv;
        if(say == l) {
            for(it = ind.begin(); it != ind.end(); it ++) {
                //cout<<it->first / it->second<<" ";
                mx = max(mx , it->first / it->second);
                mn = min(mn , it->first / it->second);
            }
            if(min_diff > mx / mn) {
                cvb_ind = ind;
                min_diff = mx / mn;
            }
        }

    }
    for(int i = 0; i < n; i ++) {
        cout<<cvb_ind[a[i]] << " ";
    }


}

