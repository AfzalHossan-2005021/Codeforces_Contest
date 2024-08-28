#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vll a(n+1);
        vi dp(n+2);
        for(int i = 1; i <= n; i++) cin >> a[i];
        partial_sum(a.begin(), a.end(), a.begin());
        for(int i = n - 1; ~i; i--){
            int j = upper_bound(a.begin(), a.end(), a[i]+x) - a.begin();
            dp[i] = dp[j] + j - i - 1;
        }
        cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
    }
    return 0;
}