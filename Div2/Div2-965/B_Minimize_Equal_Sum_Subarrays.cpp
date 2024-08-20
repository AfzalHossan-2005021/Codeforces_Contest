#include<bits/stdc++.h>

using namespace std;

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
        vi a(n);
        cin >> a[n-1];
        for(int i = 0; i < n-1; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}