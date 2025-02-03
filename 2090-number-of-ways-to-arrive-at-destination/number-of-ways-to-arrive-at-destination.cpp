typedef long long int lli;
#define MOD 1000000007
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<pair<lli,lli>>> adj(n);
        for(auto i : roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<lli> dis(n,LLONG_MAX),w(n,0);
        dis[0] = 0;
        w[0] = 1;
        set<pair<lli,lli>> st;
        st.insert({0,0});
        while(st.size() > 0){
            auto it = *(st.begin());
            auto [dst , curr] = it;
            st.erase(it);
            for(auto i : adj[curr]){
                if(dst + i.second < dis[i.first]){
                    dis[i.first] = dst + i.second;
                    w[i.first] = w[curr];
                    st.insert({dis[i.first],i.first});
                }else if(dst + i.second == dis[i.first]){
                    w[i.first] = (w[i.first] + w[curr])%MOD;
                }
            }
        }
        return w[n-1];
    }
};