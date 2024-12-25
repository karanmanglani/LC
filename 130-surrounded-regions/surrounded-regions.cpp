class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j,vector<vector<bool>>& vis){
        int m = board.size(), n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n ) return ;
        if(vis[i][j]) return;
        vis[i][j] = true;
        if(board[i][j] == 'X') return;
        dfs(board,i-1,j,vis);
        dfs(board,i+1,j,vis);
        dfs(board,i,j-1,vis);
        dfs(board,i,j+1,vis);
    }

    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        for(int i = 0;i < m;i++){
            if(!vis[i][0]) dfs(board,i,0,vis);
            if(!vis[i][n-1]) dfs(board,i,n-1,vis);
        }

        for(int i = 0;i < n;i++){
            if(!vis[0][i]) dfs(board,0,i,vis);
            if(!vis[m-1][i]) dfs(board,m-1,i,vis);
        }

        for(int i = 0; i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'O' and !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};