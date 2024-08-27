#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, c, k;
        string s;
        cin >> n >> c >> k >> s;
        int mx_mask = 1 << c, cur_mask = 0;
        vector<bool> bad(mx_mask, false);
        vector<int> cnt(c, 0);
        bad[1 << (s[n - 1] - 'A')] = true;
        for(int i = 0; i < k - 1; i++){
            int ch = s[i] - 'A';
            if(!cnt[ch]) cur_mask |= (1 << ch);
            cnt[ch]++;
        }
        for(int i = k - 1; i < n; i++){
            int ch = s[i] - 'A';
            if(!cnt[ch]) cur_mask |= (1 << ch);
            cnt[ch]++;
            bad[cur_mask] = true;
            ch = s[i - k + 1] - 'A';
            cnt[ch]--;
            if(!cnt[ch]) cur_mask &= ~(1 << ch);
        }
        int ans = c;
        for(int mask = 0; mask < mx_mask; mask++){
            if(!bad[mask]){
                ans = min(ans, c - __builtin_popcount(mask));
            } else {
                for(int i = 0; i < c; i++){
                    bad[mask | (1 << i)] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}