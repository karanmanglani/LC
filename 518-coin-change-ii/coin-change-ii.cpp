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
        cin.tie(0) -> sync_with_stdio(false);
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(amount, 0, coins,dp);
    }
};