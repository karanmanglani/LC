typedef long long int lli;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        cin.tie(0) -> sync_with_stdio(0);
        if(changed.size() & 1) return {};
        map<lli,lli> mp;
        vector<int> ans;
        for(auto i : changed){
            mp[i]++;
        }
        for(auto &i : mp){
            while(i.second > 0){
                if(mp[2*i.first] <= 0) return {};
                mp[i.first]--;
                mp[2*i.first]--;
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};