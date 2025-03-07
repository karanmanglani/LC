class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        int i = nums.size() - 1;
        while(i > 0 and nums[i-1] >= nums[i])i--;
        if(i == 0){
            reverse(nums.begin(),nums.end());
            return ;
        }
        int j = nums.size() - 1;
        while(j >= i and nums[j] <= nums[i-1])j--;
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i, nums.end());
        return ;
    }
};