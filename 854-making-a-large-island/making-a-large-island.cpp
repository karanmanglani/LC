typedef int lli;
class DisjointSet {
    
public:
    vector<lli> parent;
    vector<lli> rank;
    vector<lli> size;
    DisjointSet(lli n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(lli i = 0;i <= n;i++){
            parent[i] = i;
        }
    }

    lli fup(lli node){
        if(parent[node] == node) return node;
        return parent[node] = fup(parent[node]);
    }

    void ubr(lli u, lli v){
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv){
            if(rank[pu] < rank[pv]){
                swap(pu, pv);
            }
            parent[pv] = pu;
            if(rank[pu] == rank[pv]){
                rank[pu]++;
            }
        }
    }

    int ubs(lli u, lli v){
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv){
            if(size[pu] < size[pv]){
                swap(pu, pv);
            }
            size[pu] += size[pv];
            size[pv] = 0;
            parent[pv] = pu;
        }
        return size[pu];
    }
};



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        cin.tie(0) -> sync_with_stdio(0);
        lli ans = 0;
        lli n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        DisjointSet ds(n*n);
        for(lli i = 0;i < n;i++){
            for(lli j = 0;j < n;j++){
                if(grid[i][j] == 1) {
                    ans = max(ans,ds.size[ds.fup(n*i+j)]);
                    lli ns = 1;
                    // i - 1, j
                    int ni = i-1, nj = j;
                    if(ni < n and nj < n and ni >= 0 and nj >= 0 and grid[ni][nj] == 1){
                        if(ds.fup(n*i + j) != ds.fup(ni*n + nj)){
                            ns = ds.ubs(n*i + j, ni*n + nj);
                            ans = max(ans,ns);
                        }
                    }

                    // i + 1, j
                    ni = i+1;nj = j;
                    if(ni < n and nj < n and ni >= 0 and nj >= 0 and grid[ni][nj] == 1){
                        if(ds.fup(n*i + j) != ds.fup(ni*n + nj)){
                            ns = ds.ubs(n*i + j, ni*n + nj);
                            ans = max(ans,ns);
                        }
                    }

                    // i , j - 1
                    ni = i;nj = j-1;
                    if(ni < n and nj < n and ni >= 0 and nj >= 0 and grid[ni][nj] == 1){
                        if(ds.fup(n*i + j) != ds.fup(ni*n + nj)){
                            ns = ds.ubs(n*i + j, ni*n + nj);
                            ans = max(ans,ns);
                        }
                    }

                    // i , j+1
                    ni = i;nj = j+1;
                    if(ni < n and nj < n and ni >= 0 and nj >= 0 and grid[ni][nj] == 1){
                        if(ds.fup(n*i + j) != ds.fup(ni*n + nj)){
                            ns = ds.ubs(n*i + j, ni*n + nj);
                            ans = max(ans,ns);
                        }
                    }
                }
            }
        }

        for(lli i = 0;i < n;i++){
            for(lli j = 0;j < n;j++){
                if(grid[i][j] == 0) {
                    lli curr = 1;
                    lli ni = i-1,nj = j;
                    vector<lli> chk;
                    if(ni < n and nj < n and ni >=0 and nj >= 0 and grid[ni][nj] == 1){
                        curr += ds.size[ds.fup(ni*n + nj)];
                        chk.push_back(ni*n + nj);
                    }

                    ni = i+1;nj = j;
                    if(ni < n and nj < n and ni >=0 and nj >= 0 and grid[ni][nj] == 1){
                        bool flag = true;
                        for(auto it : chk){
                            if(ds.fup(it) == ds.fup(ni*n +nj)) {flag = false;break;}
                        }
                        if(flag) curr += ds.size[ds.fup(ni*n + nj)];
                        chk.push_back(ni*n + nj);
                    }

                    ni = i;nj = j-1;
                    if(ni < n and nj < n and ni >=0 and nj >= 0 and grid[ni][nj] == 1){
                        bool flag = true;
                        for(auto it : chk){
                            if(ds.fup(it) == ds.fup(ni*n +nj)) {flag = false;break;}
                        }
                        if(flag) curr += ds.size[ds.fup(ni*n + nj)];
                        chk.push_back(ni*n + nj);
                    }

                    ni = i;nj = j+1;
                    if(ni < n and nj < n and ni >=0 and nj >= 0 and grid[ni][nj] == 1){
                        bool flag = true;
                        for(auto it : chk){
                            if(ds.fup(it) == ds.fup(ni*n +nj)) {flag = false;break;}
                        }
                        if(flag) curr += ds.size[ds.fup(ni*n + nj)];
                        chk.push_back(ni*n + nj);
                    }
                    ans = max(ans,curr);
                }
            }
        }

        return ans;
    }
};