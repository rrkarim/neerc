/**
*/
#include <bits/stdc++.h>
#define MAXN 211005
#define MINF -1000000000000
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7ll;

int n;
map <string, int> mp;
map <string, int>::iterator it;
string s;
vector <string> vi;
int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        int index = s.find('.');
        s = s.substr(index + 1);
        mp[s] += 1;
        if(mp[s] == 1) vi.push_back(s);
    }
    for(int i = 0; i < vi.size(); ++i) cout << vi[i] << ": " << mp[vi[i]] << endl;
}
