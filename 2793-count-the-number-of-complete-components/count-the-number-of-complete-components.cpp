class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        int ans = 0, cnt = 0,ed = 0;
        for(int i = 0;i <n;i++){
            if(!vis[i]){
                [&](){
                    queue<int> q;
                    q.push(i);
                    vis[i] = true;
                    while(!q.empty()){
                        int f = q.front();
                        q.pop();
                        cnt++;
                        ed += adj[f].size();
                        for(auto it : adj[f]){
                            if(!vis[it]) q.push(it);
                            vis[it] = true;
                        }
                    }
                    if(cnt*(cnt-1) == ed) ans++;
                    cnt = 0;
                    ed=0;
                }();
                
            }
        }
        return ans;
    }
};