class Solution {
public:
    int uniquePaths(int m, int n) {
        cin.tie(0) -> sync_with_stdio(0);
        // vector<vector<int>> dp(m, vector<int> (n,-1));
        // dp[0][0] = 1;
        // for(int i = 0;i < m;i++){
        //     for(int j = 0;j < n;j++){
        //         if(i == 0 and j == 0) continue;
        //         else if(i > 0 and j > 0) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //         else if(i > 0) dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = dp[i][j-1];
        //     }
        // }
        // return solve(m-1,n-1,dp);

        vector<int> column(n,1);
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                column[j] += (j == 1) ? 1 : column[j-1];
            }
        }
        return column[n-1];
    }
};