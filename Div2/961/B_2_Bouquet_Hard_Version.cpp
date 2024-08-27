#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
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
        ll n, m;
        cin >> n >> m;
        vector<pll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].f;
        }
        for(int i = 0; i < n; i++){
            cin >> a[i].s;
        }
        sort(a.begin(), a.end());
        ll ans = a[n-1].f * min(m / a[n-1].f, a[n-1].s);
        for(int i = 0; i < n-1; i++){
            if(a[i].f + 1 == a[i+1].f){
                ll p = min(m / a[i].f, a[i].s);
                ll rem = m - p * a[i].f;
                ll q = min(rem / a[i+1].f, a[i+1].s);
                rem -= q * a[i+1].f;
                ll r = min(min(rem, p), a[i+1].s - q);
                p -= r;
                q += r;
                ans = max(ans, p * a[i].f + q * a[i+1].f);
            }
            ans = max(ans, a[i].f * min(m / a[i].f, a[i].s));
        }
        cout << ans << endl;
    }
    return 0;
}