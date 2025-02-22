class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        cin.tie(0) -> sync_with_stdio(0);
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> column(n,1);
        bool flag = false;
        for(int i = 0;i < n;i++) if(obstacleGrid[0][i] || flag) {column[i] = 0;flag = true;}
        for(int i = 1;i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j]) {column[j] = 0;continue;}
                if(j != 0) column[j] += column[j-1];
            }
        }
        return column[n-1];
        
    }
};