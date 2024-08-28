#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >> n >> a >> b;
        int first_one = -1, first_missmatch = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == '1' && first_one == -1){
                first_one = i;
            }
            if(a[i] != b[i] && first_missmatch == -1){
                first_missmatch = i;
            }
            if(first_one != -1 && first_missmatch != -1){
                break;
            }
        }
        if(first_missmatch == -1 || first_one == 0){
            cout << "YES\n";
        } else if(first_one == -1){
            cout << "NO\n";
        } else if(first_missmatch < first_one){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}