class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> t(n+1,INT_MAX);
        set<pair<int,int>> st;
        st.insert({0,k});
        t[k] = 0;
        while(st.size() > 0){
            auto it = *(st.begin());
            auto [tm,cur] = it;
            st.erase(it);
            for(auto i : adj[cur]){
                if(t[i.first] > tm + i.second){
                    t[i.first] = tm + i.second;
                    st.insert({t[i.first],i.first});
                }
            }
        }
        int ans  = INT_MIN;
        for(int i = 1;i <= n;i++) ans = max(ans,t[i]);
        return (ans != INT_MAX ) ? ans : -1;
    }
};