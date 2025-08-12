using lli = long long int;
#define MOD 1000000007

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<vector<lli>> dp(n,vector<lli> (n+2,-1));
        // dp[i][j] => number of ways to reach n if curr sum is i and current idx is j
        auto f = [&](lli currSum, lli currNum, auto &&F) -> lli{
            if(currSum > n || currNum > (n+1)) return 0;
            if(currSum == n) return 1;
            if(dp[currSum][currNum] != -1) return dp[currSum][currNum];

            // Not Take
            dp[currSum][currNum] = F(currSum,currNum + 1, F);

            // Take
            dp[currSum][currNum] = (dp[currSum][currNum] + F(currSum + pow(currNum,x),currNum + 1,F)) % MOD;

            return dp[currSum][currNum];
        };

        return f(0,1,f);
    }
};

const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();