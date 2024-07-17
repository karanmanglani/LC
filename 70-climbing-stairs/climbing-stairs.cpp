class Solution {
public:

    int solveTopDown(int n, vector<int> &dp){
        if(n == 1 or n == 0 or n == 2) return n;
        if(dp[n] != -1) return dp[n];

        dp[n] = solveTopDown(n-1,dp) + solveTopDown(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        int Ans = solveTopDown(n,dp);
    
        return Ans;
    }
};