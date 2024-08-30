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
        int n, tmp, odd = 0, even = 0;
        cin >> n;
        vector<int> st(n);
        vi ans;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            st[i] = tmp;
            if(tmp & 1) odd++;
            else even++;
        }
        if(odd && even){
            cout << -1 << endl;
            continue;
        }
        int sub = 1 << 30;
        for(int i = 0; i < 30; i++){
            sub >>= 1;
            for(int j = 0; j < n; j++){
                st[j] = abs(st[j] - sub);
            }
            ans.push_back(sub);
        }
        int ones = 0, zeros = 0;
        for(int i = 0; i < n; i++){
            if(st[i] == 1) ones++;
            else if(st[i] == 0) zeros++;
        }
        if(ones == n || zeros == n){
            if(ones == n){
                ans.push_back(1);
            }
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}