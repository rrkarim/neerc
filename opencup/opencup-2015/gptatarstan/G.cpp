#include <bits/stdc++.h>
using namespace std;
int a[11111];
int mx = 0;
int main() {
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> x;
        a[x] ++;
    }

    for(int i = 0; i <= 10000; i++)
        mx = max(mx , a[i]);

    cout<<mx<<endl;
    return 0;
}
