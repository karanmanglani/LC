class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int i, vector<int>& clr, int cl){
        bool ans = true;
        clr[i] = cl;
        for(auto x: graph[i]){
            if(clr[x] == -1) ans = ans & dfs(graph,x,clr,cl ^ 1);
            else if(clr[x] == cl) return false;
        }

        return ans;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = graph.size();
        vector<int> clr(n,-1);
        for(int i = 0;i < n;i++){
            if(clr[i] == -1){
                if(!dfs(graph,i,clr,0)) return false;
            }
        }
        return true;
    }
};