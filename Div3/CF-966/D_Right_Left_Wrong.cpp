#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<long long>
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vll a(n+1);
        a[0] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        string s;
        cin >> s;
        stack<int> left, right;
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') right.push(i+1);
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'L') left.push(i);
        }
        for(int i = 1; i <= n; i++){
            a[i] += a[i-1];
        }
        ll ans = 0;
        while(!left.empty() && !right.empty()){
            int l = left.top();
            int r = right.top();
            if(l > r) break;
            left.pop();
            right.pop();
            ans += a[r] - a[l];
        }
        cout << ans << endl;
    }
    return 0;
}