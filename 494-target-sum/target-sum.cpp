class Solution {
public:

    int solve(int idx, int tgt, vector<int> &nums,vector<vector<int>> &dp){
        if(tgt < -1000 or tgt > 1000) return 0;
        if(idx == 0){
            int ans = 0;
            if(tgt == -nums[idx]) ans++;
            if(tgt == nums[idx]) ans++;
            return dp[idx][tgt+1000] =  ans;
        }
        if(dp[idx][tgt+1000] != -1) return dp[idx][tgt+1000];
        int ans = 0;
        int pos = solve(idx-1,tgt-nums[idx],nums,dp);
        int neg = solve(idx-1,tgt + nums[idx],nums,dp);
        if(pos != 0) ans += pos;
        if(neg != 0) ans += neg;
        return dp[idx][tgt+1000] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (2001,-1));
        return solve(n-1,target,nums,dp);
    }
};