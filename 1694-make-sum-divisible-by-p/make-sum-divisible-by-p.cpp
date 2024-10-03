typedef long long int lli;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        lli rem = 0;
        lli n = nums.size();
        for(int i = 0;i < n; i++){
            rem = (rem % p + nums[i]%p)%p;
        }
        if(rem == 0) return 0;
        unordered_map<int,int> x;
        x[0] = -1;
        lli cs = 0;
        lli ans = n;
        for(int i = 0;i < n;i++){
            cs = (cs%p + nums[i]%p)%p;
            lli pfx = (((cs - rem)%p) + p)%p;
            if (x.contains(pfx)){
                lli len = i - x[pfx];
                ans = (len < ans) ? len : ans;
            }
            x[cs] = i;
        }

        return (ans < n)? ans : -1;
        return ans;
    }
    
};