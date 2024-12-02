#include <bits/stdc++.h>
class Solution {
public:
    void dfs(vector<vector<bool>> &adj, int n, int m, int i, int j, vector<vector<bool>> &vis) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (adj[i][j] && !vis[i][j]) {
            vis[i][j] = true;
            dfs(adj, n, m, i - 1, j, vis); // Up
            dfs(adj, n, m, i + 1, j, vis); // Down
            dfs(adj, n, m, i, j - 1, vis); // Left
            dfs(adj, n, m, i, j + 1, vis); // Right
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> adj(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') adj[i][j] = true;
            }
        }
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && adj[i][j]) {
                    dfs(adj, m, n, i, j, vis);
                    ans++; 
                }
            }
        }
        return ans;
    }
};
