class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};