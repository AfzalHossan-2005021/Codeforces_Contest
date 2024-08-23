#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define endl "\n"

const int MOD = 1e9 + 7;
vi fact(200001, 1);

int binary_exp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int mod_inv(int a){
    return binary_exp(a, MOD - 2);
}

int nCr(int n, int r){
    if(r > n) return 0;
    int div = (1LL * fact[r] * fact[n - r]) % MOD;
    return (fact[n] * 1LL * mod_inv(div)) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < 200001; i++){
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int &x : a) cin >> x;
        sort(a.begin(), a.end());
        vi suf_one(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            suf_one[i] = suf_one[i + 1] + (a[i] == 1);
        }
        ll ans = 0;
        int half_k = k >> 1;
        for(int i = half_k; i < n; i++){
            if(a[i]){
                int one = suf_one[i+1] - suf_one[n];
                if(one < half_k) continue;
                ans += (nCr(i, half_k) * 1LL * nCr(one, half_k)) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
    return 0;
}