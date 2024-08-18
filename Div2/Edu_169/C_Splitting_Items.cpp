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
        int n, k, tmp;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = (n & 1); i < n; i += 2){
            ans += a[i+1] - a[i];
            if(k > 0){
                if(k >= ans){
                    k -= ans;
                    ans = 0;
                } else {
                    ans -= k;
                    k = 0;
                }
            }
        }
        if(n & 1) ans += a[0];
        cout << ans << endl;
    }
    return 0;
}