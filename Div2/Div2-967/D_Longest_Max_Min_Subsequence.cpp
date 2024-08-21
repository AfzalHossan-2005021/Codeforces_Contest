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
        int n, unique = 0;
        cin >> n;
        int a[n];
        vi cnt(n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(cnt[a[i]] == 0) unique++;
            cnt[a[i]]++;
        }
        vi ans(unique+1);
        vector<bool> in_ans(n+1, false);
        auto is_better = [&](int val, int indx){
            if(indx & 1){
                return val < ans[indx];
            } else {
                return val > ans[indx];
            }
        };
        int pos = 0;
        for(int i = 0; i < n; i++){
            cnt[a[i]]--;
            if(in_ans[a[i]]) continue;
            if(pos > 0) {
                while((pos > 0 && is_better(a[i], pos-1) && cnt[ans[pos-1]] > 0) || (pos > 1 && is_better(a[i], pos-2) && cnt[ans[pos-1]] > 0 && cnt[ans[pos-2]] > 0)){
                    if(pos > 1 && is_better(a[i], pos-2) && cnt[ans[pos-1]] > 0 && cnt[ans[pos-2]] > 0){
                        in_ans[ans[--pos]] = false;
                    }
                    in_ans[ans[--pos]] = false;
                }
            }
            ans[pos++] = a[i];
            in_ans[a[i]] = true;
        }
        cout << unique << endl;
        for(int i = 0; i < unique; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}