typedef long long lli;
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        cin.tie(0) -> sync_with_stdio(0);
        set<pair<int,int>> st;
        int x = 0;
        int n = nums.size();
        vector<bool> vis(n);
        lli sum = 0;
        for(int i = 0;i < n;i++){
            st.insert({nums[i],i});
            sum += nums[i];
        }
        vector<lli> ans;
        for(auto i : queries){
            int idx = i[0], k = i[1];
            if(!vis[idx]){
                vis[idx] = true;
                sum -= nums[idx];
                st.erase(st.find({nums[idx],idx}));
            }

            while(st.size() > 0 and k--){
                auto it = *st.begin();
                sum -= it.first;
                vis[it.second] = true;
                st.erase(st.begin());
            }
            ans.push_back(sum);
        }
        return ans;
    }
};