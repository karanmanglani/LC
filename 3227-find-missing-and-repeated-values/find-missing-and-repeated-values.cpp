class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = grid.size();
        vector<int> vis(n*n,0);
        for(auto i : grid){
            for(auto j : i){
                vis[j-1]++;
            }
        }
        vector<int> ans(2,0);
        for(int i = 0;i < n*n;i++){
            if(vis[i] == 0) ans[1] = i+ 1;
            if(vis[i] == 2) ans[0] = i+1;
        }
        return ans;
    }
};