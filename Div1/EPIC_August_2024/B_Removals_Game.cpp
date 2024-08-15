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
        int n; cin >> n;
        vi a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        bool same = true;
        int alice_front = 0, bob_front = 0, alice_back = n - 1, bob_back = n-1;
        for(int i = 1; i < n; i++){
            if((a[alice_front] != b[bob_front] && a[alice_front] != b[bob_back]) || (a[alice_back] != b[bob_front] && a[alice_back] != b[bob_back])){
                same = false;
                break;
            } else if(a[alice_front] == b[bob_front]){
                alice_front++;
                bob_front++;
            } else if(a[alice_back] == b[bob_back]){
                alice_back--;
                bob_back--;
            } else if(a[alice_front] == b[bob_back]) {
                alice_front++;
                bob_back--;
            } else if(a[alice_back] == b[bob_front]){
                alice_back--;
                bob_front++;
            }
        }
        if(same) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    return 0;
}