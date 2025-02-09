class Solution {
public:
    int t = 0;
    void dfs(int i, vector<int> &tin, vector<int> &low, vector<bool>& vis,vector<vector<int>>& adj, int pt,vector<vector<int>>& ans){
        tin[i] = low[i] = t++;
        vis[i] = true;
        for(auto it : adj[i]){
            if(it == pt) continue;
            if(!vis[it]){
                dfs(it, tin, low, vis, adj,i, ans);
                low[i] = min(low[i], low[it]);
                if(low[it] > tin[i]) ans.push_back({it,i});
            }else {
                low[i] = min(low[i],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<int>> adj(n);
        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> low(n,INT_MAX), tin(n,INT_MAX);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        dfs(0,tin,low,vis, adj,-1, ans);
        return ans;
    }
};