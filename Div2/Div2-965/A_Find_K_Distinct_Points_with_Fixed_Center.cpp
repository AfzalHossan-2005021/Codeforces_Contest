#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        int x_left, x_right, y_up, y_down;
        if(k & 1){
            x_left = x;
            x_right = x;
            y_up = y;
            y_down = y;
            cout << x << " " << y << endl;
            k--;
        } else {
            x_left = x - 1;
            x_right = x + 1;
            y_up = y + 1;
            y_down = y - 1;
            cout << x_left << " " << y_down << endl;
            cout << x_right << " " << y_up << endl;
            k -= 2;
        }
        while(k){
            cout << --x_left << " " << --y_down << endl;
            cout << ++x_right << " " << ++y_up << endl;
            k-=2;
        }
    }
    return 0;
}