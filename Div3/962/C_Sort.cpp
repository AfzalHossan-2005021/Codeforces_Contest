#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        string a, b;
        cin >> n >> q >> a >> b;
        vector<vi> a_cnt(n+1, vi(26)), b_cnt(n+1, vi(26));
        for(int i=0; i<n; i++){
            int nxt_idx = i+1;
            for(int j=0; j<26; j++){
                a_cnt[nxt_idx][j] = a_cnt[i][j];
                b_cnt[nxt_idx][j] = b_cnt[i][j];
            }
            a_cnt[nxt_idx][a[i]-'a']++;
            b_cnt[nxt_idx][b[i]-'a']++;
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int i=0; i<26; i++){
                ans += abs((a_cnt[r][i] - a_cnt[l-1][i]) - (b_cnt[r][i] - b_cnt[l-1][i]));
            }
            cout << (ans/2) << endl;
        }
    }
    return 0;
}