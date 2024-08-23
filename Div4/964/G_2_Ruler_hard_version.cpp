#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

int main(){
    int t;
    cin >> t;
    while(t--){
        int low = 1, high = 1000;
        while(low <= high){
            int area, diff_by_3 = (high - low) / 3;
            int one_third = low + diff_by_3;
            int two_third = one_third + diff_by_3;
            cout << "? " << one_third << " " << two_third << endl;
            cin >> area;
            if(area == one_third * two_third){
                low = two_third + 1;
            } else if(area == one_third * (two_third+1)){
                low = one_third + 1;
                high = two_third - 1;
            } else {
                high = one_third - 1;
            }
        }
        cout << "! " << low << endl;
    }
    return 0;
}