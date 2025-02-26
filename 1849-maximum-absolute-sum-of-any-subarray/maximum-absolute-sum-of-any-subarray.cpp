class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        int sum = 0, ans = 0,n = nums.size();
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(sum < 0) sum = 0;
            ans = max(ans,sum);
        }
        for(auto &i : nums) i = i * -1;
        sum =  0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(sum < 0) sum = 0;
            ans = max(ans,sum);
        }
        return ans;
    }
};