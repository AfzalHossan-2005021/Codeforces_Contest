#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        int lb = 1, ub = 1e9;
        while(lb <= ub){
            int md = (lb + ub) / 2;
            vi b(n), dp(n);
            for(int i = 0; i < n; i++){
                if(a[i] < md) b[i] = -1;
                else b[i] = 1;
            }
            for(int i = 0; i < n; i++){
                dp[i] = b[i];
                if(i % k) dp[i] += dp[i-1];
                if(i >= k) dp[i] = max(dp[i], dp[i-k]);
            }
            if(dp.back() > 0){
                lb = md + 1;
            } else {
                ub = md - 1;
            }
        }
        cout << ub << endl;
    }
    return 0;
}