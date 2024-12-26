typedef long long int lli;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        lli n = nums.size();
        vector<int> ans(n,-1);
        if(n <= 2*k) return ans;
        lli sum = 0;
        for(lli i = 0; i <= 2*k;i++) sum += nums[i];
        ans[k] = sum / (2*k + 1);
        for(lli i = k + 1; i + k < n;i++){
            sum += nums[i + k] - nums[i - k - 1];
            ans[i] = sum/(2*k + 1);
        }
        return ans;
    }
};