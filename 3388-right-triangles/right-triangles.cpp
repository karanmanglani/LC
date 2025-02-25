class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        int m = grid.size(), n = grid[0].size();
        vector<int> r(m,0), c(n,0);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                r[i] += grid[i][j];
                c[j] += grid[i][j];
            }
        }
        long long ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans += grid[i][j] *(r[i] - 1)*(c[j] - 1);
            }
        }
        return ans;
    }
};