class Solution {
public:
    void solve(int i, vector<vector<int>>& adj, map<int, int>& mp,
               vector<bool>& vis, int& ans, int cost, int t,
               vector<int>& amount) {
        vis[i] = true;
        if (t < mp[i]) {
            cost += amount[i];
        } else if (t == mp[i]) {
            cost += amount[i] / 2;
        }
        bool flag = true;
        for (auto it : adj[i]) {
            if (!vis[it]) {
                flag = false;
                vis[it] = true;
                solve(it, adj, mp, vis, ans, cost, t + 1, amount);
            }
        }
        if (flag)
            ans = max(ans, cost);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        cin.tie(0)->sync_with_stdio();
        vector<vector<int>> adj(amount.size());
        int n = amount.size();
        vector<bool> vis1(n, false), vis2(n, false);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(bob);
        parent[bob] = bob; 

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == 0)
                break; 
            for (int nxt : adj[cur]) {
                if (nxt == parent[cur])
                    continue;
                parent[nxt] = cur;
                q.push(nxt);
            }
        }

        vector<int> path;
        int cur = 0;
        while (cur != bob) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(bob);
        reverse(path.begin(), path.end());
        map<int, int> mp;
        for (int i = 0; i < path.size(); i++) {
            mp[path[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (mp[i] == 0 and i != bob)
                mp[i] = INT_MAX;
        }
        int ans = INT_MIN;
        solve(0, adj, mp, vis2, ans, 0, 0, amount);
        return ans;
    }
};