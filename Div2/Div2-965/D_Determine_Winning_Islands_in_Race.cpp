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
        int n, m;
        cin >> n >> m;
        vi ans(n-1, 1);
        vector<vi> edges_toward(n), edges_from(n);
        for(int i = 0; i < n - 1; i++){
            edges_toward[i].push_back(i+1);
            edges_from[i+1].push_back(i);
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(u > v) swap(u, v);
            edges_toward[u].push_back(v);
            edges_from[v].push_back(u);
        }
        vi dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < edges_from[i].size(); j++){
                dp[i] = min(dp[i], dp[edges_from[i][j]] + 1);
            }
        }
        int checked = 0;
        for(int i = 0; i < n - 1; i++){
            int mx_jmp = *max_element(edges_toward[i].begin(), edges_toward[i].end());
            int steps = dp[i] + 1;
            int diff = mx_jmp - steps;
            for(int j = max(i+1, checked); j < diff; j++){
                ans[j] = 0;
            }
            checked = max(checked, diff);
        }
        for(int i = 0; i < n - 1; i++){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}