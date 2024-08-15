#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m, k, w;
        cin >> n >> m >> k >> w;
        vi a(w);
        for(int &x : a) cin >> x;
        sort(a.rbegin(), a.rend());
        vll grid(n * m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i*m+j] = min(k, min(i + 1, n - i)) * 1LL * min(k, min(j + 1, m - j));
                if(i+k > n) grid[i*m+j] = min(grid[i*m+j], grid[(i-1)*m+j]);
                if(j+k > m) grid[i*m+j] = min(grid[i*m+j], grid[i*m+j-1]);
            }
        }
        sort(grid.rbegin(), grid.rend());
        ll ans = 0;
        for(int i = 0; i < w; i++){
            ans += grid[i] * a[i];
        }
        cout << ans << endl;
    }
    return 0;
}