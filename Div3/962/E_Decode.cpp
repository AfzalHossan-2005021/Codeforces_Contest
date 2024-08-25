#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

const int M = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        map<int, set<int>> mp;
        mp[0].insert(0);
        int one_cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                one_cnt++;
            } else {
                one_cnt--;
            }
            mp[one_cnt].insert(i+1);
        }
        ll ans = 0;
        for(auto &x: mp){
            ll mult = 0, tmp_ans = 0;
            for(auto &y: x.s){
                tmp_ans += (mult * (n - y + 1)) % M;
                tmp_ans %= M;
                mult += y+1;
                mult %= M;
            }
            ans += tmp_ans;
            ans %= M;
        }
        cout << ans << endl;
    }
    return 0;
}