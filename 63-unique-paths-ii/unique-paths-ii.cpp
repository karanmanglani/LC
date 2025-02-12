class Solution {
public:
    int solve(int m, int n , vector<vector<int>>&arr, vector<vector<int>>& dp){
        if(arr[m][n] == 1) return dp[m][n] = 0;
        if(m == 0 and n == 0) return dp[m][n] = 1; 
        if(dp[m][n] != -1){
            if(dp[m][n] == 0) return 0;
            else return dp[m][n];
        }
        if(m > 0 and n > 0) {
            int x = solve(m-1,n,arr,dp);
            int y = solve(m, n-1, arr,dp);
            if(x == 0 and y == 0) return dp[m][n] =  0;
            else if(x == 0) return dp[m][n] = y;
            else if(y == 0) return dp[m][n] = x;
            else return dp[m][n] =  x + y;
        }else if(m > 0){
            int x = solve(m-1,n,arr,dp);
            if(x == 0) return dp[m][n] = 0;
            else return dp[m][n] =  x;
        }else{
            int x = solve(m,n-1,arr,dp);
            if(x == 0) return dp[m][n] =  0;
            else return dp[m][n] = x;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        cin.tie(0) -> sync_with_stdio(0);
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(m-1,n-1,arr,dp);
    }
};