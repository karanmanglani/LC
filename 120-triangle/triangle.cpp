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
        vector<vector<int>> dp(n, vector<int> (triangle[n-1].size(),-1));
        int ans = INT_MAX;
        for(int i = 0;i < triangle[n-1].size() ; i++){
            ans = min(ans, solve(triangle,n-1,i,dp));
        }
        return ans;
    }
};