typedef long long int lli;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        map<pair<lli,lli>,vector<pair<lli,lli>>> adj;
        lli n = grid[0].size();
        if(n == 1) {
            if(grid[0][0]) return -1;
            else return 1;
        }
        else if(grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;
        for(lli i = 0;i < n;i++){
            for(lli j = 0;j < n;j++){
                if(grid[i][j] != 0) continue;
                lli ni = i-1, nj = j - 1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i -1;nj = j;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i -1;nj = j + 1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i;nj = j - 1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i;nj = j+1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i +1;nj = j-1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i +1;nj = j;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
                ni = i +1;nj = j+1;
                if(ni >= 0 and nj >= 0 and ni < n and nj < n and grid[ni][nj] == 0) adj[{i,j}].push_back({ni,nj});
            }
        }

        map<pair<lli,lli>, lli> dist;
        set<pair<lli,pair<lli,lli>>> st;
        st.insert({1,{0,0}});
        while(st.size() > 0){
            auto it = *(st.begin());
            lli a = it.first;
            auto b = it.second;
            st.erase(it);
            for(auto it : adj[b]){
                if(dist[it] == 0 || dist[it] > (a+1)) {
                    dist[it] = a + 1;
                    st.insert({a+1,{it}});
                }
            }
        }

        if(dist[{n-1,n-1}] == 0) return -1;
        else return dist[{n-1,n-1}];
    }
};