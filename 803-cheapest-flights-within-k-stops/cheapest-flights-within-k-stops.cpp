typedef long long int lli;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<pair<lli,lli>>> adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        set<pair<lli,pair<lli,lli>>> st;
        vector<vector<lli>> p(n,vector(n+2,LLONG_MAX));
        p[src][0] = 0;
        st.insert({0,{src,0}});
        while(st.size() > 0){
            auto it = *(st.begin());
            lli cpr = it.first;
            lli curr = it.second.first;
            lli stp = it.second.second;
            st.erase(it);
            if(stp >= k+1) continue;
            for(auto i : adj[curr]){
                if(p[i.first][stp+1] > cpr + i.second){
                    p[i.first][stp+1] = cpr + i.second;
                    st.insert({p[i.first][stp+1],{i.first,stp+1}});
                }
            }
        }
        lli ans = LLONG_MAX;
        for(auto i : p[dst]) ans = min(ans,i);
        return (ans != LLONG_MAX) ? ans : -1;
    }
};