class Solution {
public:

    int solve(vector<int>& nums , int idx, vector<int>& dp ){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int money = nums[idx];
        dp[idx] =  money + max(solve(nums,idx + 2,dp) , solve(nums,idx + 3,dp)); 
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return max(solve(nums,0,dp),solve(nums,1,dp));
    }
};