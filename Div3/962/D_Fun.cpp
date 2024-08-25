#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n, x, ans = 0;
        cin >> n >> x;
        for(ll a = 1; a < x - 1; a++){
            for(ll b = 1; b < n / a && b < x-a; b++){
                ans += min(((n - a * b) / (a + b)), x - (a + b));
            }
        }
        cout << ans << endl;
    }
    return 0;
}