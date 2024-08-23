#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while(test--){
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        int i=0, j = 0;
        for(; i < n; i++){
            if(j < m){
                if(s[i] == '?'){
                    s[i] = t[j];
                    j++;
                } else if(s[i] == t[j]){
                    j++;
                }
            } else {
                if(s[i] == '?'){
                    s[i] = 'a';
                }
            }
        }
        if(j < m){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << s << endl;
        }
    }
    return 0;
}