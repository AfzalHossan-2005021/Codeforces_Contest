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
        int n;
        cin >> n;
        vi a(n);
        for(int &x : a) cin >> x;
        vi vanished(n);
        vector<pii> ans;
        for(int i = n - 1; i; i--){
            vi modulo_pos(i, -1);
            for(int j = 0; j < n; j++){
                if(!vanished[j]){
                    if(modulo_pos[a[j] % i] == -1) modulo_pos[a[j] % i] = j;
                    else{
                        vanished[j] = 1;
                        ans.push_back({j+1, modulo_pos[a[j] % i]+1});
                        break;
                    }
                }
            }
        }
        cout << "YES" << endl;
        for(int i = n - 2; ~i; i--) cout << ans[i].f << " " << ans[i].s << endl;
    }
    return 0;
}