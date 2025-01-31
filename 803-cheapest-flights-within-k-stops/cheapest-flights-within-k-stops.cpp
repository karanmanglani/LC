class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
       // {price, {node, level}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> fare(n, vector<int>(k+2, 1e9));
        pq.push({0, {src, 0}});
        fare[src][0]=0;
        while(!pq.empty()){
            auto[pr, nl] = pq.top();
            auto[node, level] = nl;
            pq.pop();
            for(auto it:adj[node]){
                int nxt = it.first;
                int newlevel = level+1;
                int newpr = pr+it.second;
                if(newlevel<k+2 && nxt<n && fare[nxt][newlevel]>newpr){
                    fare[nxt][newlevel]=newpr;
                    pq.push({newpr, {nxt, newlevel}});
                }
                
            }
        }
        int ans =1e9;
        for(int i=0; i<=k+1; i++){
            ans = min(ans, fare[dst][i]);
        }
        if(ans == 1e9) return -1;
        return ans;

    }
};