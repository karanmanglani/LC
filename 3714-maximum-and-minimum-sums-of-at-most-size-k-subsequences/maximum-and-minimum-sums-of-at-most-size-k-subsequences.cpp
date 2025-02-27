#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
#define MOD 1000000007

lli be(lli n, lli p) { // TC -> O(log(p))
    lli x = n;
    lli ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ans * x;
        }
        x *= x;
        p >>= 1;
    }
    return ans;
}

lli bem(lli n, lli p) { // TC -> O(log(p % (MOD - 1)))
    p = p % (MOD - 1);
    lli x = n;
    lli ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ((ans % MOD) * (x % MOD)) % MOD;
        }
        x = (x * x) % MOD;
        p >>= 1;
    }
    return ans;
}



lli mi(lli x) { // TC -> O(log(MOD))
    return bem(x, MOD - 2);
}


lli mod_mul(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;} // TC -> O(1)
lli mod_sub(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;} // TC -> O(1)

pair<vector<lli>, vector<lli>> pcf(lli n){
    vector<lli> fct(n+1,1), ifct(n+1,1);
    for(lli i = 1;i <= n;i++){
        fct[i] = (fct[i-1]*i)%MOD;
    }
    ifct[n] = mi(fct[n]);
    for(lli i = n-1;i >= 1;i--){
        ifct[i] = (ifct[i+1]*(i+1))%MOD;
    }
    return {fct,ifct};
}

lli ncrf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if (r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[r]) % MOD;
    res = (res * ifct[n - r]) % MOD;
    return res;
}

lli nprf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if (r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[n - r]) % MOD;
    return res;
}


class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        cin.tie(0) -> sync_with_stdio(false);
        lli n = nums.size(), ans = 0;
        map<lli,lli> mp;
        for(auto i : nums) mp[i]++;
        sort(nums.begin(),nums.end());
        auto x = pcf(1e5);
        auto fct =x.first, ifct = x.second;
        for(lli l = 1;l <= k;l++){
            lli sm = 0, bg = n;
            for(auto i : mp){
                bg -= i.second;
                for(lli j = 1;j <= min(l,i.second);j++){
                    ans = (ans + ( ( __int128 ) i.first * ncrf(i.second, j, fct, ifct) % MOD *
                ( (ncrf(sm, l-j, fct, ifct) + ncrf(bg, l-j, fct, ifct)) % MOD) ) % MOD) % MOD;

                    ans %= MOD;
                }
                sm += i.second;
            }
        }
        int anss = ans % MOD;
        return anss;
    }
};