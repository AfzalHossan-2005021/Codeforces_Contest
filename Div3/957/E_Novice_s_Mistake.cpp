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
        int digit = log10(n) + 1;
        int mx = 1e4;
        mx *= n;
        int mult = 1;
        for(int i = 0; i < digit; i++){
            mult *= 10;
        }
        ll na = n;
        while(na < mx){
            na = na * mult + n;
        }
        vi possible;
        while(na){
            if(na <= mx){
                possible.push_back(na);
            }
            na /= 10;
        }
        reverse(possible.begin(), possible.end());
        vector<pii> ans;
        for(int i = 0; i < possible.size(); i++){
            for(int a = 1; a <= 10000; a++){
                int b = digit * a - (i + 1);
                if(b > 0 && b <= min(10000, n * a) && n * a - b == possible[i]){
                    ans.push_back({a, b});
                }
            }
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].f << " " << ans[i].s << endl;
        }
    }
    return 0;
}