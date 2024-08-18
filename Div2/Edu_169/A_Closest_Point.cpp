#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, tmp;
        cin >> n;
        unordered_set<int> x;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            x.insert(tmp);
        }
        if(x.size() == 1){
            cout << "YES\n";
        } else if(x.size() == 2){
            int mn = *min_element(x.begin(), x.end());
            int mx = *max_element(x.begin(), x.end());
            if(mx - mn > 1){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}