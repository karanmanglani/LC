class Solution {
public:

    int solve(int amt, vector<int>& coins,vector<int> &dp){
        if(amt == 0) return dp[amt] =  0;
        if(dp[amt] != -2) return dp[amt];
        int x = INT_MAX;
        for(auto i : coins){
            int z;
            if(i <= amt){
                z = 1 + solve(amt-i,coins,dp);
                if(z != 0) x = min(z,x);
            }
        }
        return dp[amt] =  (x != INT_MAX) ? x : -1;
    }

    int coinChange(vector<int>& coins, int amount) {
        cin.tie(0) -> sync_with_stdio(false);
        if(amount == 0) return 0;
        int ans = INT_MAX;
        vector<int> dp(amount+1,-2);
        for(auto i : coins){
            int z;
            if(i <= amount) {
                z =1 +  solve(amount-i,coins,dp);
                if(z != 0) ans = min(ans,z);
            }
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};