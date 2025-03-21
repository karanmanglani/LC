class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        cin.tie(0) -> sync_with_stdio(false);
        unordered_map<string,vector<string>> adj,adj2;
        unordered_map<string,int> cnt;
        int n = recipes.size();
        for(int i  = 0;i < n;i++){
            for(auto j : ingredients[i]) {adj[recipes[i]].push_back(j);adj2[j].push_back(recipes[i]);}
            cnt[recipes[i]] = ingredients[i].size();
        }
        for(auto i : supplies){
            for(int j = 0;j < n;j++){
                for(auto k : ingredients[j]) if(k == i) cnt[recipes[j]]--;
            }
        }
        queue<string> q;
        vector<string> ans;
        for(auto i : recipes){
            if(cnt[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            string top = q.front();
            q.pop();
            for(auto i : adj2[top]){
                cnt[i]--;
                if(cnt[i] == 0){
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};