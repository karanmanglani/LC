typedef long long int lli;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        lli n = nums.size();
        vector<int> s(n,0);
        lli ans = -1, mx = -1;
        s[n-1] = nums[n-1];
        for(lli i = n-2;i >= 0 ;i--){
            s[i] = max(s[i+1],nums[i]);
        }
        for(lli i = 0;i < n-1;i++){
            if(mx == -1) mx = nums[i];
            else {
                ans = max(ans, s[i+1] * (mx - nums[i]));
                mx = max(mx,1LL*nums[i]);
            }
        }
        return ans>0 ? ans : 0;
    }
};