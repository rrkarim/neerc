#include <bits/stdc++.h>

using namespace std;
bool qual(int a[] , int b[]) {
    if(a[0] > b[0]) return true;
    if(a[0] < b[0]) return false;
    if(a[1] > b[1]) return true;
    if(a[1] < b[1]) return false;
    if(a[2] > b[2]) return true;
    if(a[2] < b[2]) return false;
    return false;
}
bool quan(int a[] , int b[]) {
    if(a[0] + a[1] + a[2] > b[0] + b[1] + b[2])
        return true;
    return false;
}
int main() {
    int n;
    cin >> n;
    int a[3];
    int b[3];
    for(int i = 0; i < n; i ++) {
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
        if(qual(a, b) && quan(a , b))
            cout<<"Win"<<endl;
        else
        if(qual(a , b))
            cout<<"Quality"<<endl;
        else
        if(quan(a , b))
            cout<<"Count"<<endl;
        else
        cout<<"None"<<endl;
    }


    return 0;
}
