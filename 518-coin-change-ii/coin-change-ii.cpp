class Solution {
public:
    int solve(int amt, int idx, vector<int> &coins, vector<vector<int>> &dp) {
        if (amt == 0) return 1;
        if (amt < 0) return 0;
        if(dp[idx][amt] != -1) return dp[idx][amt];
        int ans = 0;
        for (int i = idx; i < coins.size(); i++) {
            ans += solve(amt - coins[i], i, coins,dp);
        }
        return dp[idx][amt] =  ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<unsigned _BitInt(50)> dp(amount + 1, 0);
        dp[0] = 1; 
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};