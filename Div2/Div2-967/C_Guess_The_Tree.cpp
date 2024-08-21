#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define endl "\n"

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> parent(n+1);
        for(int i = 2; i <= n; i++){
            int u = -1, x = 1;
            while(x != i){
                u = x;
                cout << "? " << i << " " << u << endl;
                cin >> x;
            }
            parent[i] = u;
        }
        cout << "!";
        for(int i = 2; i <= n; i++){
            cout << " " << parent[i] << " " << i;
        }
        cout << endl;
    }
    return 0;
}