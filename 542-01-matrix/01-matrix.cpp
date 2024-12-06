class Solution {
public:

    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n));
        vector<vector<bool>> vis(m, vector<bool> (n,false));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(mat[i][j] == 0) {
                    q.push({0,{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int l = f.first, i = f.second.first, j = f.second.second;
            ans[i][j] = l;
            vector<pair<int,int>> diff = {{-1,0}, {1,0}, {0 , -1}, {0 , 1}};
            for(auto z : diff){
                int ni = i + z.first , nj = j + z.second;
                if(ni >= 0 && nj >= 0 && ni < m and nj < n and !vis[ni][nj]){
                    q.push({l+1, {ni,nj}});
                    vis[ni][nj] = true;
                }
            }
        }
        return ans;
    }
};