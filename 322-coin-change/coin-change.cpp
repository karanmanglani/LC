class Solution {
public:

    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1 , INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amt ; i++){
            for(int j : coins){
                if(i - j >= 0 and dp[i-j] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - j]);
                }
            }
        }

        return (dp[amt] != INT_MAX) ? dp[amt] : -1;
    }
};