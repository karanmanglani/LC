class Solution {
public:

    void solve(int i , vector<vector<int>> &adj,vector<vector<bool>> &poscol, vector<bool> &vis,vector<int> &ans){
        if(vis[i]) return ;
        vis[i] = true;
        for(auto it : adj[i]){
            if(vis[it]){
                poscol[i][ans[it]-1] = false; 
            }
        }
        int idx = 0;
        while(!poscol[i][idx])idx++;
        ans[i] = idx+1;
        for(auto it: adj[i]){
            if(!vis[it]){
                solve(it,adj,poscol,vis,ans);
            }
        }

    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> ans(n,-1);
        vector<vector<int>> adj(n);
        for(auto i : paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        vector<vector<bool>> posCol(n,vector<bool> (4,true));
        vector<bool> vis(n,false);
        for(int i = 0;i < n;i++){
            if(!vis[i]) solve(i,adj,posCol,vis,ans);
        }
        return ans;
    }
};