class Solution {
public:

    int solve(vector<vector<int>> &arr, int i , int j,vector<vector<int>> &dp){
        if(i == 0) return arr[0][0];
        int cost = arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        if(j == 0) cost += solve(arr,i-1,j,dp);
        else if(j == i) cost += solve(arr,i-1,j-1,dp);
        else cost += min(solve(arr,i-1,j,dp), solve(arr,i-1,j-1,dp));
        return dp[i][j] = cost;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        cin.tie(0) -> sync_with_stdio(0);
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (triangle[n-1].size(),INT_MAX));
        int ans = INT_MAX;
        dp[0][0] = triangle[0][0];
        for(int i = 1;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(j == 0) dp[i][j] = triangle[i][j] + dp[i-1][j];
                else if(j == i) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                else dp[i][j] = triangle[i][j] + min(dp[i-1][j] , dp[i-1][j-1]);
            }
        }
        for(auto i : dp[n-1]) ans = min(ans,i);
        return ans;
    }
};