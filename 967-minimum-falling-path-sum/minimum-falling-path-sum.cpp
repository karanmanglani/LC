class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = matrix.size();
        vector<int> row(n),curr(n);
        for(int i = 0;i < n;i++) row[i] = curr[i] = matrix[0][i];
        for(int i = 1;i < n;i++){
            for(int j = 0;j < n;j++){
                if(j == 0) curr[j] = matrix[i][j] + min(row[j],row[j+1]);
                else if(j == n-1) curr[j] = matrix[i][j] + min(row[j],row[j-1]);
                else curr[j] = matrix[i][j] + min(row[j], min(row[j+1],row[j-1]));
            }
            row = curr;
        }
        int ans = INT_MAX;
        for(auto i : curr) ans = min(ans , i);
        return ans;
    }
};