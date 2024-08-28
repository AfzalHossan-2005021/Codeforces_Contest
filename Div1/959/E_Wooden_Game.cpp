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
        int k, tmp;
        cin >> k;
        vi a(k);
        for(int &x : a){
            cin >> x;
            for(int i = 1; i < x; i++) cin >> tmp;
        }
        sort(a.rbegin(), a.rend());
        unsigned int ans = a[0];
        for(int i = 1; i < k; i++){
            unsigned int target = (~ans);
            unsigned int tmp_ans = 0;
            unsigned int tmp_target = (1 << 31);
            for(int j = 31; ~j; j--){
                if(target & tmp_target){
                    if((tmp_ans | tmp_target) <= a[i]){
                        tmp_ans |= tmp_target;
                    }
                }
                tmp_target >>= 1;
            }
            ans |= tmp_ans;
        }
        cout << ans << endl;
    }
    return 0;
}