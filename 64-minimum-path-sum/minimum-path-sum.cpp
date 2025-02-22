class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        int m = grid.size(), n = grid[0].size();
        vector<int> a(n,0);
        for(int i = 0;i < n;i++) a[i] = (i == 0) ? grid[0][i] : grid[0][i] + a[i-1];
        for(int i = 1;i < m;i++){
            for(int j = 0;j < n;j++){
                a[j] = (j == 0) ? a[j] + grid[i][j] : min(a[j], a[j-1]) + grid[i][j];
            }
        }
        return a[n-1];
    }
};