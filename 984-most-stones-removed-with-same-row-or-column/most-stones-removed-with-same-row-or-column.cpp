class DisjointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0;i <= n;i++){
            parent[i] = i;
        }
    }

    int fup(int node){
        if(parent[node] == node) return node;
        return parent[node] = fup(parent[node]);
    }

    void ubr(int u, int v){
        int pu = fup(u);
        int pv = fup(v);
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

    void ubs(int u, int v){
        int pu = fup(u);
        int pv = fup(v);
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
    int removeStones(vector<vector<int>>& stones) {
        cin.tie(0) -> sync_with_stdio(0);
        int n = stones.size();
        int mr = 0, mc = 0;
        for(auto i : stones) {
            mr = max(mr,i[0]);
            mc = max(mc,i[1]);
        }

        DisjointSet ds(mr + mc + 1);
        set<int> comp;
        for(auto i : stones){
            ds.ubs(i[0], mr+i[1]+1);
            comp.insert(i[0]);
            comp.insert(i[1] + mr + 1);
        }
        int cnt = 0;
        for(auto i : comp){
            if(ds.fup(i) == i) cnt++;
        }
        return n - cnt;
    }
};