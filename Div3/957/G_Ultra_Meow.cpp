#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define endl "\n"

const int mod = 1e9 + 7;

int mod_inv(int a){
    int b = mod - 2;
    int res = 1;
    while(b){
        if(b & 1) res = (res * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return res;
}

int nCr(int n, int r, vi &fact){
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    return (fact[n] * 1LL * mod_inv(((fact[r] * 1LL * fact[n-r]) % mod))) % mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi fact(5000+1);
    fact[0] = 1;
    for(ll i = 1; i <= 5000; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll ans = 1;
        for(int i = 1; i <= (n -1) / 2; i++){
            for(int j = i + 1; j <= 2 * i + 1; j++){
                int p = j - 1;
                int q = p - i;
                ll ncr1 = nCr(p, q, fact);
                ll ncr2 = nCr(n - j, i - q, fact);
                ans += (((j * ncr1) % mod) * ncr2) % mod;
                ans %= mod;
            }
        }
        for(ll i = (n + 1) / 2; i <= n; i++){
            ans += ((2 * i + 1) * nCr(n, i, fact)) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}