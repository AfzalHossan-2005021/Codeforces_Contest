#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int MX_N = 1e7;
    vi spf(MX_N+1, -1);
    vi pref_sp(MX_N+1, -1);
    int prime_index = 1;
    for(int i = 2; i <= MX_N; i++){
        if(spf[i] == -1){
            spf[i] = i;
            for(ll j = 1LL*i*i; j <= MX_N; j += i){
                if(spf[j] == -1) spf[j] = i;
            }
            pref_sp[i] = prime_index++;
        }
    }
    auto grundy = [&](int x){
        if(x == 1) return 1;
        else if(x & 1) return pref_sp[spf[x]];
        else return 0;
    };
    int t;
    cin >> t;
    while(t--){
        int n, tmp;
        cin >> n >> tmp;
        int ans = grundy(tmp);
        for(int i = 1; i < n; i++){
            cin >> tmp;
            ans ^= grundy(tmp);
        }
        cout << (ans ? "Alice" : "Bob") << endl;
    }
    return 0;
}