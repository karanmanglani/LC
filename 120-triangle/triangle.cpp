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
        vector<int> row(n,0);
        vector<int> curr(n,0);
        row[0] = triangle[0][0];
        curr[0] =row[0];
        for(int i = 1;i < n;i++){
            for(int j = 0;j <= i;j++){
                if(j == 0) curr[j] = triangle[i][j] + row[j];
                else if(j == i) curr[j] = triangle[i][j] + row[j-1];
                else curr[j]= triangle[i][j] + min(row[j] , row[j-1]);
            }
            row = curr;
        }
        for(auto i : row) ans = min(ans,i);
        return ans;
    }
};