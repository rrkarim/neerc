#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    //freopen("doubling.in","r",stdin);
    //freopen("doubling.out","w",stdout);
    cin >> n;
    while(n!=0){
        if(n&1 || n<4){
            cout << '1'; --n;
        } else{
            cout << '['; ++k; n >>= 1;
        }
    }
    while(k--) cout << ']';
    return 0;
}
