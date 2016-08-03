/**
*/
#include <bits/stdc++.h>
#define MAXN 211005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

map <string, int> mp;
map <string, int>::iterator it;
string s;
vector <string> vi;
int n, x, y, xt, yt;
int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> y;
    for(int i = 0; i < n; ++i) {
        cin >> xt >> yt;
        cout << xt + (yt - y) << " " << yt - (xt + yt - x - y) << endl;
    }
}
