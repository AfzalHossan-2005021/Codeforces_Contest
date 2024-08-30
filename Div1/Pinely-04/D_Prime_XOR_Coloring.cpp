#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define endl "\n"

const int N = 1 << 3;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < N; i++){
        if(is_prime[i]){
            for(int j = i * i; j < N; j += i){
                is_prime[j] = false;
            }
        }
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n < N){
            vi ans(n+1, 1);
            set st {1};
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(is_prime[i ^ j]) st.insert(ans[j] = ans[i] + 1);
                }
            }
            cout << st.size() << endl;
            for(int i = 1; i <= n; i++){
                cout << ans[i] << " ";
            }
        } else {
            cout << 4 << endl;
            for(int i = 0; i < n; i++){
                cout << (i % 4) + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}