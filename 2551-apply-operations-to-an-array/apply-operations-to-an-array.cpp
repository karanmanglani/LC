class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> ans;
        for(auto i : nums) if(i != 0) ans.push_back(i);
        while(ans.size() < nums.size()) ans.push_back(0);
        return ans;
    }
};