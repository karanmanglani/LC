class Solution {
public:

    int solve(int idx, int tgt, vector<int> &nums,map<pair<int,int>,int> &dp){
        if(idx == 0){
            int ans = 0;
            if(tgt == -nums[idx]) ans++;
            if(tgt == nums[idx]) ans++;
            return dp[{idx,tgt}] =  ans;
        }
        if(dp.find({idx,tgt}) != dp.end()) return dp[{idx,tgt}];
        int ans = 0;
        int pos = solve(idx-1,tgt-nums[idx],nums,dp);
        int neg = solve(idx-1,tgt + nums[idx],nums,dp);
        if(pos != 0) ans += pos;
        if(neg != 0) ans += neg;
        return dp[{idx,tgt}] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = nums.size();
        map<pair<int,int>,int> dp;
        return solve(n-1,target,nums,dp);
    }
};