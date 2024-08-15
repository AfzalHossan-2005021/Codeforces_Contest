#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        cin >> m;
        while(m--){
            string s;
            cin >> s;
            if(s.length() == n){
                bool ok = true;
                vector<int> b(26, INT_MAX);
                map<char, int> mp1;
                map<int, char> mp2;
                for(int i = 0; i < n; i++){
                    if(mp1.find(s[i]) == mp1.end() && mp2.find(a[i]) == mp2.end()){
                        mp1[s[i]] = a[i];
                        mp2[a[i]] = s[i];
                    } else if(mp1.find(s[i]) != mp1.end() && mp2.find(a[i]) != mp2.end()){
                        if(mp1[s[i]] != a[i] || mp2[a[i]] != s[i]){
                            ok = false;
                            break;
                        }
                    } else {
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}