class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
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
        }
        int cnt = 0;
        for(auto i : ind) if(i == 0) cnt++;
        return cnt == n;
    }
};