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
        vi a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int tartle = 1;
        int lb = 0, ub = n-1;
        while(lb < ub){
            if(tartle){
                lb++;
            }else{
                ub--;
            }
            tartle ^= 1;
        }
        cout << a[lb] << endl;
    }
    return 0;
}