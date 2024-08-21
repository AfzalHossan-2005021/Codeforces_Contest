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
        if(n & 1){
            vi ans(n);
            int elem = 1;
            for(int i = n / 2; i < n; i++){
                ans[i] = elem;
                elem ++;
            }
            for(int i = n / 2 - 1; i >= 0; i--){
                ans[i] = elem;
                elem ++;
            }
            for(int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}