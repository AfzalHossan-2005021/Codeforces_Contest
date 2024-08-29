#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int &i : a) cin >> i;
        int ans = 1;
        set st {x};
        for(int &i : a){
            for(int y : st){
                if(y == i) {
                    st = {x, x / i};
                    ans++;
                    break;
                } 
                if(y % i == 0){
                    st.insert(y / i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}