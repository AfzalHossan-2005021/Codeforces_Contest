#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi even, odd;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x & 1) odd.push_back(x);
            else even.push_back(x);
        }
        if(odd.size() == n || even.size() == n){
            cout << 0 << endl;
        } else {
            ll odd_mx = *max_element(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            int op_cnt = 0;
            for(int i = 0; i < even.size(); i++){
                if(even[i] < odd_mx){
                    op_cnt++;
                    odd_mx += even[i];
                } else {
                    op_cnt += 2;
                    odd_mx += even[even.size() - 1];
                }
            }
            cout << op_cnt << endl;
        }

    }
    return 0;
}