class Solution {
public:

    // Recursive Solution
    int solve(vector<int>& cost , int n){
        // Base Case
        if(n == 0 or n == 1) return cost[n];

        return min(solve(cost,n-1), solve(cost,n-2)) + cost[n];
    }

    int solveRM(vector<int>& cost , int n , vector<int>& dp){
        if(n == 0 or n == 1) return cost[n];

        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(solveRM(cost,n-1,dp), solveRM(cost,n-2,dp));
        return dp[n];
    }

    int solveT(vector<int>& cost , int n , vector<int>& dp){
        

        for(int i = 2; i <= n ; i++) {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Recursive solution
        // return min(solve(cost,n-1), solve(cost,n-2));
        
        // Dynamic Programming
        //vector<int> dp(n+1,-1);
        // Recursion + Memoisation 
        //return min(solveRM(cost , n-1, dp),solveRM(cost , n-2,dp));

        // Tabulation
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        //return min(solveT(cost , n-1, dp),solveT(cost , n-2,dp));

        // Tabulation + space Optimization
        int prev = cost[1];
        int prePrev = cost[0];
        for(int i = 2; i < n ; i++){
            int curr = cost[i] + min(prev , prePrev);
            prePrev = prev;
            prev = curr; 
        }

        return min(prev, prePrev);

    }
};