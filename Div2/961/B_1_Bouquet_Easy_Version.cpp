#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n, m, x;
        cin >> n >> m;
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> x;
            mp[x]++;
        }
        ll ans = 0;
        for(auto p : mp){
            ll op_one = min(p.s, m / p.f);
            ans = max(ans, op_one * p.f);
            if(mp.find(p.f + 1) != mp.end()){
                ll op_two = min(mp[p.f + 1], m / (p.f + 1));
                ll total = min(p.s + mp[p.f + 1], m / p.f);
                for(ll i = 1; i <= op_one; i++){
                    ll j = min((m - i * p.f) / (p.f + 1), op_two);
                    ans = max(ans, i * p.f + j * (p.f + 1));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}