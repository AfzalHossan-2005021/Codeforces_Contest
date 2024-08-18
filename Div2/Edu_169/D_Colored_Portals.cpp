#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int type_cast(string s){
    if( s == "BG") return 0;
    if( s == "BR") return 1;
    if( s == "BY") return 2;
    if( s == "GR") return 3;
    if( s == "GY") return 4;
    if( s == "RY") return 5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        string s;
        cin >> n >> q;
        vi type(n+1);
        for(int i = 1; i <= n; i++){
            cin >> s;
            type[i] = type_cast(s);
        }
        vector<pii> dp(n+1);
        vi nearest(6, n+1);
        for(int i = n; i >= 1; i--){
            nearest[type[i]] = i;
            dp[i].f = n + 1;
            for(int j = 0; j < 6; j++){
                if(j == type[i] || j == 5 - type[i]) continue;
                dp[i].f = min(dp[i].f, nearest[j]);
            }
        }
        nearest.assign(6, 0);
        for(int i = 1; i <= n; i++){
            nearest[type[i]] = i;
            dp[i].s = 0;
            for(int j = 0; j < 6; j++){
                if(j == type[i] || j == 5 - type[i]) continue;
                dp[i].s = max(dp[i].s, nearest[j]);
            }
        }
        while(q--){
            int x, y;
            cin >> x >> y;
            if(x > y) swap(x, y);
            if(type[x] + type[y] != 5){
                cout << abs(x - y) << endl;
                continue;
            }
            if(dp[x].f == n+1 && dp[y].s == 0){
                cout << -1 << endl;
            } else if(dp[x].f == n+1){
                cout << abs(x - dp[x].s) + abs(y - dp[x].s) << endl;
            } else if(dp[x].s == 0){
                cout << abs(y - dp[x].f) + abs(x - dp[x].f) << endl;
            } else {
                cout << min(abs(x - dp[x].s) + abs(y - dp[x].s), abs(y - dp[x].f) + abs(x - dp[x].f)) << endl;
            }
        }
    }
    return 0;
}