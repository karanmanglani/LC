class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        set<pair<int,pair<int,int>>> st;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mn(m,vector<int> (n,INT_MAX));
        mn[0][0] = 0;
        st.insert({grid[0][0],{0,0}} );
        int ans = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int d = it.first, i = it.second.first, j = it.second.second;
            st.erase(st.begin());
            if(i == m-1 and j == n-1) {
                ans = d;
                break;
            }
            if(i + 1 < m and (d + grid[i+1][j]) < mn[i+1][j]) {st.insert({d + grid[i+1][j],{i+1,j}}); mn[i+1][j] = d + grid[i+1][j];}
            if(j + 1 < n and (d + grid[i][j+1]) < mn[i][j+1]) {st.insert({d+grid[i][j+1],{i,j+1}});mn[i][j+1] = grid[i][j+1] + d;}
        }
        return ans;
    }
};