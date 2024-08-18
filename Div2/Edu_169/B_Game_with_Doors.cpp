#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int mx_l = max(l1, l2);
        int mn_r = min(r1, r2);
        int overlap = max(-1, mn_r - mx_l);
        if(l1 < mx_l || l2 < mx_l) overlap++;
        if(r1 > mn_r || r2 > mn_r) overlap++;
        cout << overlap << endl;        
    }
    return 0;
}