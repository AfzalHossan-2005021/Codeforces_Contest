#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define endl "\n"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pii> a(n);
        for(auto &x : a) cin >> x.f >> x.s;
        pii start, end;
        cin >> start.f >> start.s >> end.f >> end.s;
        ll dist = abs(start.f - end.f) * 1LL * abs(start.f - end.f) + abs(start.s - end.s) * 1LL * abs(start.s - end.s);
        ll mn_dst = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll dst = abs(a[i].f - end.f) * 1LL * abs(a[i].f - end.f) + abs(a[i].s - end.s) * 1LL * abs(a[i].s - end.s);
            mn_dst = min(mn_dst, dst);
        }
        if(mn_dst > dist) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}