class Solution {
public:

    int solve(int m, int n,vector<vector<int>>& dp){
        if(dp[m][n] != -1) return dp[m][n];
        else if(m > 0 and n > 0) return dp[m][n] = solve(m-1,n,dp) + solve(m,n-1,dp);
        else if(m > 0) return dp[m][n] = solve(m-1,n,dp);
        else if(n > 0) return dp[m][n] = solve(m,n-1,dp);
        else return 0;
    }

    int uniquePaths(int m, int n) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0] = 1;
        return solve(m-1,n-1,dp);
    }
};