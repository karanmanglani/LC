class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> ans(n,-1);
        vector<vector<bool>> pos(n, vector<bool> (4,true));
        vector<vector<int>> adj(n);
        for(auto i : paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        for(int i = 0;i < n;i++){
            for(auto it : adj[i]){
                if(ans[it] != -1) pos[i][ans[it]-1] = false;
            }
            int idx = 0;
            while(!pos[i][idx]) idx++;
            ans[i] = idx+1;
        }
        return ans;
    }
};