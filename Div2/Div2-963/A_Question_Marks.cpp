#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        vector<int> cnt(4, 0);
        int q = (n << 2);
        for(int i = 0; i < q; i++){
            char c;
            cin >> c;
            if(c == '?') continue;
            cnt[c - 'A']++;
        }
        for(int i = 0; i < 4; i++){
            ans += min(cnt[i], n);
        }
        cout << ans << endl;
    }
    return 0;
}