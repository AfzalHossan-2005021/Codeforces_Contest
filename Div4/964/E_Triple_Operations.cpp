#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int low = l, high = 1;
        int div = 0;
        while(low){
            low /= 3;
            high *= 3;
            div++;
        }
        ll op_cnt = div;
        r++;
        for(int i = high; i < r * 3; i*=3){
            i = min(i, r);
            op_cnt += div * (i - l);
            l = i;
            div++;
        }
        cout << op_cnt << endl;
    }
    return 0;
}