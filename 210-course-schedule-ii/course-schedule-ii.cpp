class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> ind(n,0);
        vector<vector<int>> adj(n);
        for(auto i : p) {
            ind[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(ind[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
                ind[i]--;
                if(ind[i] == 0) {
                    q.push(i);
                }
            }
            ans.push_back(node);
        }
        if(ans.size() != n) ans.clear();
        return ans;
    }
};