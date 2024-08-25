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
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        for(int &x: a) cin >> x;
        for(int &x: b) cin >> x;
        int mn_lim = INT_MAX;
        ll ans = 0;
        int lb = 1, ub = 1e9;
        while(lb <= ub){
            int md = (lb+ub) >> 1;
            ll op_cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] >= md){
                    op_cnt += (a[i] - md) / b[i] + 1;
                }
            }
            if(op_cnt <= k){
                ub = md - 1;
                mn_lim = min(mn_lim, md);
            } else {
                lb = md + 1;
            }
        }
        priority_queue<pii> pq;
        for(int i = 0; i < n; i++){
            if(a[i] >= mn_lim){
                int op = (a[i] - mn_lim) / b[i] + 1;
                int low = a[i] - op * b[i];
                pq.push({low, b[i]});
                low += b[i];
                ans += op * 1LL * (low + a[i]) / 2LL;
                k -= op;
            } else {
                pq.push({a[i], b[i]});
            }
        }
        while(k > 0 && !pq.empty()){
            pii p = pq.top();
            if(p.f <= 0) break;
            pq.pop();
            ans += p.f;
            p.f -= p.s;
            pq.push(p);
            k--;
        }
        cout << ans << endl;
    }
    return 0;
}