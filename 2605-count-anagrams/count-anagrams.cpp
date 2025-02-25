typedef long long int lli;
#define MOD 1000000007

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


class Solution {
public:
    int countAnagrams(string s) {
        cin.tie(0) -> sync_with_stdio(0);
        auto [fct,ifct] = pcf(1e5);
        int n = s.size();
        map<char,lli> mp;
        int cnt = 0;
        int ans = 1;
        for(int i = 0;i < n;i++){
            if(s[i] == ' '){
                lli x = fct[cnt];
                cnt = 0;
                for(auto i : mp) {
                    x = (x * ifct[i.second]) % MOD;
                }
                ans = (ans * x)%MOD;
                mp.clear();
            }else {
                mp[s[i]]++;
                cnt++;
            }
        }
        lli x = fct[cnt];
        for(auto i : mp) {
            x = (x * ifct[i.second]) % MOD;
        }
        ans = (ans * x)%MOD;
        return ans;
    }
};