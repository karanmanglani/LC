class Solution {
public:

    int solve(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp){
        int n  = nums.size();
        if(idx >= n) return 0;
        if(idx == n-1){
            if(idx & 1){
                return dp[idx][prev] = max(nums[idx],nums[prev]);
            }else{
                vector<int> temp;
                temp.push_back(nums[prev]);
                temp.push_back(nums[idx]);
                temp.push_back(nums[idx-1]);
                sort(temp.begin(),temp.end());
                return dp[idx][prev] =  temp[0] + temp[2];
            }
        }
        if(dp[idx][prev] != -1) return dp[idx][prev];
        if(idx <= 1 || (idx & 1)) return dp[idx][prev] = solve(idx+1,prev,nums,dp);
        vector<pair<int,int>> temp;
        temp.push_back({nums[prev],prev});
        temp.push_back({nums[idx],idx});
        temp.push_back({nums[idx-1],idx-1});
        sort(temp.begin(),temp.end());
        return dp[idx][prev] =  min(temp[1].first + solve(idx+1,temp[2].second,nums,dp), temp[2].first + solve(idx+1, temp[0].second,nums,dp));

    }

    int minCost(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        if(nums.size() <= 2){
            return *max_element(nums.begin(),nums.end());
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,0,nums,dp);
    }
};