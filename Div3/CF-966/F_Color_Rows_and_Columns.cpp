#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pii> a(n+1);
        for(int i = 1; i <=n; i++) cin >> a[i].f >> a[i].s;
        vector<vi> dp(n+1, vi(k+1, INF));
        for(int i = 1; i <= n; i++){
            for(int r = 0; r <= a[i].f; r++){
                for(int c = 0; c <= a[i].s; c++){
                    if(r + c > k) break;
                    int cost = r * a[i].s + c * a[i].f - r * c;
                    dp[i][r + c] = min(dp[i][r + c], cost);
                }
            }
        }
        vector<vi> dp2 = dp;
        for(int i = 1; i <= n; i++){
            for(int r = 0; r <= k; r++){
                for(int c = 0; c <= k; c++){
                    if(r + c > k) break;
                    dp2[i][r + c] = min(dp2[i][r + c], dp2[i-1][r] + dp[i][c]);
                }
            }
        }
        if(dp2[n][k] >= INF) cout << -1 << endl;
        else cout << dp2[n][k] << endl;
    }
    return 0;
}