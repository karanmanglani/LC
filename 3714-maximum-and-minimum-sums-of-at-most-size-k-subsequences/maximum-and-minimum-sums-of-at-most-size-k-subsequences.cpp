#define ll long long
const ll mod = 1e9 + 7;
const ll MAX = 100001;
vector<ll> factInverse(MAX + 1);
vector<ll> inverse(MAX + 1);
vector<ll> fact(MAX + 1);

void calcInverse()
{
    inverse[0] = inverse[1] = 1;
    for (ll i = 2; i <= MAX; i++)
        inverse[i] = (inverse[mod % i] * (mod - mod / i)) % mod;
}

void calcFactInverse()
{
    factInverse[0] = factInverse[1] = 1;
    for (ll i = 2; i <= MAX; i++)
        factInverse[i] = (inverse[i] * factInverse[i - 1]) % mod;
}

void calcFactorial()
{
    fact[0] = 1;
    for (ll i = 1; i <= MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

ll C(ll n, ll R)
{
    if (n < R || R < 0 || n < 0)
        return 0;
    ll ans = (((fact[n] * factInverse[R]) % mod) * factInverse[n - R]) % mod;
    return ans;
}

class Solution {
public:
    void init() {
        if (inverse[0] == 0) {
            calcInverse();
            calcFactInverse();
            calcFactorial();
        }
    }
    int minMaxSums(vector<int>& nums, int k) {
        init();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll ans = 0, sum = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans + (sum * ((nums[i] + nums[n - 1 - i]) % mod)) % mod) % mod;
            sum = (((2LL * sum) % mod) - C(i, k - 1) + mod) % mod;
        }
        return (int)ans;
    }
};
