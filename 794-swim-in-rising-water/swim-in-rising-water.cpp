
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        set<pair<int,pair<int,int>>> st;
        int n = grid.size();
        st.insert({grid[0][0],{0,0}});
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (n,0));
        pair<int,int> final = {n-1,n-1};
        while(st.size() > 0){
            auto it = *st.begin();
            auto val = it.first;
            auto x = it.second;
            st.erase(it);
            ans = max(ans,val);
            if(x == final) break;
            vis[x.first][x.second] = 1;
            int i = x.first - 1, j = x.second;
            if(i < n and j < n and i >= 0 and j >= 0 and !vis[i][j]) st.insert({grid[i][j],{i,j}});
            i = x.first + 1;j = x.second;
            if(i < n and j < n and i >= 0 and j >= 0 and !vis[i][j]) st.insert({grid[i][j],{i,j}});
            i = x.first;j = x.second - 1;
            if(i < n and j < n and i >= 0 and j >= 0 and !vis[i][j]) st.insert({grid[i][j],{i,j}});
            i = x.first; j = x.second + 1;
            if(i < n and j < n and i >= 0 and j >= 0 and !vis[i][j]) st.insert({grid[i][j],{i,j}});
        }
        return ans;
    }
};