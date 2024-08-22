#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        int mx = *max_element(a.begin(), a.end());
        int lb = mx, ub = mx + k - 1, twice_k = (k << 1);
        for(int i = 0; i < n; i++){
            int tmp_lb = mx - (mx - a[i]) % twice_k;
            int tmp_ub = tmp_lb + k - 1;
            if(tmp_ub < lb){
                tmp_lb += twice_k;
                tmp_ub += twice_k;
            }
            lb = max(lb, tmp_lb);
            ub = min(ub, tmp_ub);
        }
        if(lb > ub) cout << -1 << endl;
        else cout << lb << endl;
    }
    return 0;
}