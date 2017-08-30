#include <bits/stdc++.h>
#include <string>
#include <math.h>
#define INF 100000000000005
#define INFI 1073741824
#define MAXN 100004

using namespace std;
#define fir first
#define sec second
#define pb push_back
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi ;

const ll mod = 1e9 + 7ll;
int b[MAXN + 2], a[MAXN + 2], us[MAXN + 2];
unordered_map <int, int> mp, el;
vector <int> an[MAXN + 2];
int main() {
    int n; cin >> n; int ans = 0;
    for(int i = 1; i <= n; ++i) { cin >> a[i]; b[i] = a[i]; }
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; ++i) el[ b[i] ] = i;

    for(int i = 1; i <= n; ++i) {
        if(us[i]) continue;
        int curr = i, cx = 0;
        while(true) {
            us[curr] = 1;
            an[ans].push_back(curr);
            cx += 1;
            mp[ a[curr] ] += 1, mp[ b[curr] ] += 1;
            if(mp[ a[curr] ] == 2) cx -= 1;
            if(cx == 0) {
                ans += 1;
                break;
            }
            if(mp[ b[curr] ] == 2) cx -= 1;
            if(cx == 0) {
                ans += 1;
                break;
            }
            curr = el[a[curr]];
        }
    }
    cout << ans << endl;
    for(int i = 0; i < ans; ++i) {
        cout << an[i].size() << " ";
        sort(an[i].begin(), an[i].end());
        for(int j = 0; j < an[i].size(); ++j) cout << an[i][j] << " \n"[j == ans[i].size() - 1];
        cout << endl;
    }
}