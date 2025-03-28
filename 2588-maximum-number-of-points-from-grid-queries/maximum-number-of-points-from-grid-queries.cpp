class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> ans(queries.size(),-1);
        set<pair<int,int>> st;
        for(int i = 0;i < queries.size();i++){
            st.insert({queries[i],i});
        }
        auto it = st.begin();
        set<pair<int,pair<int,int>>> st2;
        int m = grid.size(), n = grid[0].size(),cnt= 0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        st2.insert({grid[0][0], {0,0}});
        vis[0][0] = true;
        while(!st2.empty()){
            auto tp =  *st2.begin();
            st2.erase(st2.begin());
            while(it != st.end() and it -> first <= tp.first){
                ans[it -> second] = cnt;
                it++;
            }
            if(it == st.end()) break;
            cnt++;
            int ni = tp.second.first - 1, nj = tp.second.second;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st2.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first + 1;nj = tp.second.second;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st2.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first;nj = tp.second.second - 1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st2.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
            ni = tp.second.first;nj = tp.second.second + 1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n and !vis[ni][nj]) {st2.insert({grid[ni][nj], {ni,nj}}); vis[ni][nj] = true;}
        }
        for(auto &i : ans) if(i == -1) i = cnt;
        return ans;
    }
};