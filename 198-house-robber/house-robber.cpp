class Solution {
public:
    int rob(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(0);
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0],nums[1]);
        int a = nums[0], b = max(nums[0], nums[1]);
        int ans;
        for(int i = 2;i < nums.size();i++){
            ans = max(b, nums[i] + a);
            if(a > b) b = a;
            a = b; b = ans;
        }
        return ans;
    }
};