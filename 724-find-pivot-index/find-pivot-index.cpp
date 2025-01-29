class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t = 0,temp=0;
        for (auto num : nums) t += num;
        for (int i = 0;i<nums.size();temp += nums[i++]) if (nums[i]==t-2*temp) return i;
        return -1;
    }
};