class Solution {
public:
    bool canPartition(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(0);
        int k = 0;
        for(auto i : nums) k += i;
        if(k &1) return false;
        else k = k/2;
        int n = nums.size();
        
        vector<int> prev(k+1,0), curr(k+1,0);
        prev[0] = 1;
        if(nums[0] <= k) prev[nums[0]] = 1;
        for(int i = 1;i < n;i++){
            for(int j = 0;j <= k;j++){
                if(prev[j]){
                    curr[j] = 1;
                    if(j + nums[i] <= k) curr[j + nums[i]] = 1;
                }
            }
            prev = curr;
        }
        return prev[k];
    }
};