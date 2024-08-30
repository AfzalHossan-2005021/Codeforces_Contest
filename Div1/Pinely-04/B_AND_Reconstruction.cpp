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
        vi b(n);
        for(int i = 1; i < n; i++){
            cin >> b[i];
        }
        vi ans(n);
        ans[0] = b[1];
        for(int i = 1; i < n - 1; i++){
            ans[i] = b[i] | b[i+1];
        }
        ans[n-1] = b[n-1];
        bool flag = true;
        for(int i = 0; i < n - 1; i++){
            if((ans[i] & ans[i+1]) != b[i+1]){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}