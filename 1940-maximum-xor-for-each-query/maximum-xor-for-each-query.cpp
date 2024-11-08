class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mx = pow(2,maximumBit) - 1;
        int n = nums.size();
        vector<int> ans(n);
        int x = 0;
        for(int i = 0;i < n;i++){
            x ^= nums[i];
            if(x == mx) ans[i] = (0);
            else ans[i] = x ^ mx;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};