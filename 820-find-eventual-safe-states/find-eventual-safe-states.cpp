class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int i, vector<int>&vis, vector<bool> &chk){
        bool ans = true;
        vis[i] = 2;
        for(auto x : graph[i]){
            if(x == i) {ans = false;continue;}
            if(vis[x] == 0)ans = ans & dfs(graph,x,vis,chk);
            else if(vis[x] == 1) ans = ans & chk[x];
            else if(vis[x] == 2) ans = false;
        }

        vis[i] = 1;
        chk[i] = ans;
        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = graph.size();
        vector<int> vis(n,0);
        vector<bool> chk(n,true);
        for(int i = 0;i < n;i++){
            if(vis[i] == 0) dfs(graph,i,vis,chk);
        }
        vector<int> ans;
        for(int i = 0;i < n;i++) if(chk[i]) ans.push_back(i);
        return ans;
    }
};