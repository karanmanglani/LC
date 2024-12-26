class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i,int j, vector<vector<bool>>& vis){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j]) return ;
        vis[i][j] = true;
        dfs(grid,i-1,j,vis);
        dfs(grid,i+1,j,vis);
        dfs(grid,i,j-1,vis);
        dfs(grid,i,j+1,vis);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m , vector<bool>(n,false));
        for(int i = 0;i < n;i++){
            if(!vis[0][i] && grid[0][i] == 1) dfs(grid,0,i,vis);
            if(!vis[m-1][i] && grid[m-1][i] == 1) dfs(grid,m-1,i,vis); 
        }

        for(int i = 0;i < m;i++){
            if(!vis[i][0] and grid[i][0] == 1) dfs(grid,i,0,vis);
            if(!vis[i][n-1] and grid[i][n-1] == 1) dfs(grid,i,n-1,vis);
        }

        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(!vis[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};