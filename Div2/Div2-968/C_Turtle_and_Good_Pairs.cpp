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
        string s;
        cin >> n >> s;
        vi cnt(26, 0);
        for(int i = 0; i < n; i++){
            cnt[s[i]-'a']++;
        }
        string ans = "";
        while(n){
            for(int i = 0; i < 26; i++){
                if(cnt[i]){
                    ans += (char)(i+'a');
                    cnt[i]--;
                    n--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}