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
        vector<pii> a(n);
        for(int i = 0; i < n; i++) cin >> a[i].f;
        for(int i = 0; i < n; i++) cin >> a[i].s;
        sort(a.begin(), a.end());
        int m_indx = n/2;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll sum = (a[i].s ? k : 0);
            if(i < m_indx){
                sum += a[i].f + a[m_indx].f;
            } else{
                sum += a[i].f + a[m_indx-1].f;
            }
            ans = max(ans, sum);
        }
        ll lb = 1, rb = 2e9;
        while(lb <= rb){
            ll tmp_k = k;
            ll md = (lb + rb) / 2;
            int indx = n - 1;
            int cnt = 0;
            for(; indx >= 0; indx--){
                if(a[indx].f < md){
                    break;
                } else{
                    cnt++;
                }
            }
            ll sum = cnt > 0 ? a[n-1].f : md;
            while(indx >= 0 && tmp_k > 0){
                if(a[indx].s){
                    ll diff = md - a[indx].f;
                    if(tmp_k >= diff){
                        tmp_k -= diff;
                        cnt++;
                    }
                }
                indx--;
            }
            if(cnt + m_indx > n){
                lb = md + 1;
                ans = max(ans, sum + md);
            } else{
                rb = md - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}