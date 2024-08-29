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
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;
        vi C_pos, L_pos(1);
        for(int i = 0; i < n; i++){
            if(s[i] == 'C'){
                C_pos.push_back(i+1);
            }else if(s[i] == 'L'){
                L_pos.push_back(i+1);
            }
        }
        int last_pos = 0, destination = n + 1;
        C_pos.push_back(INT_MAX);
        L_pos.push_back(destination);
        while(last_pos < destination){
            int next_pos = last_pos + m;
            int next_L = *upper_bound(L_pos.begin(), L_pos.end(), last_pos);
            if(next_pos < next_L){
                int next_C = *upper_bound(C_pos.begin(), C_pos.end(), last_pos);
                if(next_pos > next_C || next_C > next_L){
                    next_C = *lower_bound(C_pos.begin(), C_pos.end(), next_pos);
                    if(next_C < next_L){
                        break;
                    } else {
                        int dist_W = next_L - next_pos;
                        if(k < dist_W){
                            break;
                        } else {
                            k -= dist_W;
                            last_pos = next_L;
                        }
                    }
                } else {
                    break;
                }
            } else {
                last_pos = next_L;
            }            
        }
        if(last_pos < destination){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}