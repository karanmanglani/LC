typedef long long int lli;

class DisjointSet {
    vector<lli> parent;
    vector<lli> rank;
    vector<lli> size;
public:
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

    void ubs(lli u, lli v){
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
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        cin.tie(0) -> sync_with_stdio(0);
        int n = a.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        for(int i = 0;i < n;i++){
            for(int j = 1;j < a[i].size();j++){
                if(mp.find(a[i][j]) == mp.end()){
                    mp[a[i][j]] = i;
                }else {
                    ds.ubr(mp[a[i][j]],i);
                }
            }
        }

        vector<vector<string>> ans, mpp(n);
        for(auto it : mp){
            mpp[ds.fup(it.second)].push_back(it.first);
        }
        for(int i = 0;i < n;i++){
            if(mpp[i].size() == 0) continue;
            sort(mpp[i].begin(),mpp[i].end());
            vector<string> temp;
            temp.push_back(a[i][0]);
            for(auto it : mpp[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};