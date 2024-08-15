#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, tmp;
        cin >> n >> tmp;
        bool ok = true;
        vector<bool> v(n+2, false);
        v[tmp] = true;
        for(int i = 1; i < n; i++){
            cin >> tmp;
            if(ok){
                if(v[tmp-1] || v[tmp+1]){
                    v[tmp] = true;
                } else {
                    ok = false;
                }
            }
        }
        if(ok){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}