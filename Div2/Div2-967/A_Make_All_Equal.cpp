#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        int mx = 0;
        for(auto x: mp){
            mx = max(mx, x.s);
        }
        cout << n - mx << endl;
    }
    return 0;
}