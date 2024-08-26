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
        int n, m, mx = 0;
        cin >> n >> m;
        vector<pii> b(n);
        for(int i = 0; i < n; i++){
            int len;
            cin >> len;
            set<int> s;
            for(int j = 0; j < len; j++){
                int x;
                cin >> x;
                s.insert(x);
            }
            b[i].f = 0;
            for(auto it: s){
                if(it == b[i].f){
                    b[i].f++;
                }else{
                    break;
                }
            }
            s.insert(b[i].f);
            b[i].s = 0;
            for(auto it: s){
                if(it == b[i].s){
                    b[i].s++;
                }else{
                    break;
                }
            }
            mx = max(mx, b[i].s);
        }
        ll ans = 0;
        if(mx <= m){
            ans += mx * 1LL * mx;
            int cnt = m - mx + 1;
            ans += (m + mx) * 1LL * cnt / 2LL;
        } else {
            ans += (m + 1LL) * 1LL * mx;
        }
        cout << ans << endl;
    }
    return 0;
}