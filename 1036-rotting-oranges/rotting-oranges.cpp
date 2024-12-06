class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m , int n , int i , int j , vector<vector<int>>& vis, vector<vector<int>>& lvl,int v,int l){
        if(i < 0 || j < 0 || i >= m || j >= n|| grid[i][j] == 0) return;
        if(vis[i][j] == v and l >= lvl[i][j]) return;
        lvl[i][j] = min(lvl[i][j],l);
        vis[i][j] = v;
        dfs(grid,m,n,i-1,j,vis,lvl,v,l+1);
        dfs(grid,m,n,i+1,j,vis,lvl,v,l+1);
        dfs(grid,m,n,i,j-1,vis,lvl,v,l+1);
        dfs(grid,m,n,i,j+1,vis,lvl,v,l+1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> pos;
        bool flag = false;
        vector<vector<int>> vis(m, vector<int>(n,0)), lvl(m, vector<int>(n,INT_MAX));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) pos.push_back({i,j});
                if(grid[i][j] != 0) flag = true;
            }
        }
        if(!flag) return 0;
        if(pos.size() == 0) return -1;
        for(int i = 0;i < pos.size();i++){
            dfs(grid,m,n,pos[i].first,pos[i].second,vis,lvl,i+1,0);
        }
        int ans = INT_MIN;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cout << lvl[i][j] << " ";
            }cout << endl;
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(vis[i][j] == 0 && grid[i][j] !=  0) return -1;
                if(lvl[i][j] == INT_MAX || grid[i][j] == 0) continue;
                ans = max(ans, lvl[i][j]);
            }
        }
        return ans;
    }
};