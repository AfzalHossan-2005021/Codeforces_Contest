#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

const int N = 2e5 + 5;
vector<bool> visited(N, false);
vector<vi> adj(N);
vi mx(N);
vi elem(N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m, mx_mex1 = 0, mx_mex2 = 0;
        cin >> n >> m;
        vector<pii> edges(n);
        for(int i = 0; i < n; i++){
            int len, tmp;
            cin >> len;
            for(int j = 0; j < len; j++){
                cin >> elem[j];
                if(elem[j] < N){
                    visited[elem[j]] = true;
                }
            }
            int mex1 = 0;
            while(visited[mex1]){
                mex1++;
            }
            mx_mex1 = max(mx_mex1, mex1);
            int mex2 = mex1 + 1;
            while(visited[mex2]){
                mex2++;
            }
            mx_mex2 = max(mx_mex2, mex2);
            edges[i] = {mex1, mex2};
            for(int j = 0; j < len; j++){
                if(elem[j] < N){
                    visited[elem[j]] = false;
                }
            }
        }
        for(int i = 0; i <= mx_mex2; i++){
            adj[i].clear();
        }
        for(int i = 0; i < n; i++){
            adj[edges[i].f].push_back(edges[i].s);
        }
        for (int u = mx_mex2; u >= 0; u--) {
            mx[u] = u;
            for (int v : adj[u]) {
                mx[u] = max(mx[u], mx[v]);
            }
            if ((int)adj[u].size() > 1) {
                mx_mex1 = max(mx_mex1, mx[u]);
            }
        }
        ll ans = 0;
        int i, sz = min(mx_mex2, m);
        for(i = 0; i <= sz; i++){
            ans += max(mx_mex1, mx[i]);
        }
        if(i <= m){
            ans += (m - i + 1) * 1LL * (m + i) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}