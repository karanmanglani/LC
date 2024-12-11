typedef long long int lli;

class Solution {
public:
    bool chk(lli a , lli b , lli md,lli n){
        lli cnt = 0;
        lli lcm = a*b/__gcd(a,b);
        cnt += md/a;
        cnt += md/b;
        cnt -= md/lcm;
        return cnt >= n;
    }
    int nthMagicalNumber(int n, int a, int b) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        lli s = 0, e = 1e15;
        lli ans = LLONG_MAX;
        while(s <= e){
            lli md = s + (e-s)/2;
            if(chk(a,b,md,n)) {ans = md;e = md - 1;}
            else s = md + 1;
        }
        lli mod = 1e9 + 7;
        return ans % mod;
    }
};