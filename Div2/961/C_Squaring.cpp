#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        bool flag = false;
        ll ans = 0;
        int prev = 0;
        for(int i = 1; i < n; i++){
            ll tmp = a[i];
            int cnt = 0;
            while(tmp > a[i-1] && prev > 0){
                a[i-1] *= a[i-1];
                prev--;
            }
            while(tmp < a[i-1]){
                tmp *= tmp;
                cnt++;
                if(cnt > 6){
                    flag = true;
                    break;
                }
            }
            cnt += prev;
            ans += cnt;
            prev = cnt;
        }
        if(flag) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}