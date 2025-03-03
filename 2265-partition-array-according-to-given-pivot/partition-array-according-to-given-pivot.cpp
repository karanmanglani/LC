class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> ans;
        int cnt = 0;
        for(auto i : nums){
            if(i < pivot) ans.push_back(i);
            if(i == pivot) cnt++;
        }
        while(cnt--) ans.push_back(pivot);
        for(auto i : nums){
            if(i > pivot) ans.push_back(i);        
        }
        return ans;
    }
};