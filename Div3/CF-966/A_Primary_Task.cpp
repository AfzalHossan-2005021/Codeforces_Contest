#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int digit = log10(n) + 1;
        if(digit < 3){
            cout << "NO\n";
        } else {
            int div = pow(10, digit - 2);
            int base = n / div;
            int power = n % div;
            if(base != 10 || power < div / 10 || power < 2){
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}