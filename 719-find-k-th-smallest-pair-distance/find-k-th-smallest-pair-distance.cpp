typedef long long int lli;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        lli ans = 0;
        lli n = nums.size();
        lli s = 0 , e = 1e6;
        sort(nums.begin(),nums.end());
        while(s <= e){
            lli md = s + (e-s)/2;
            lli cnt = 0;
            for(lli i = 0;i < n;i++){
                lli j = i + 1;
                while(nums[j] - nums[i] <= md and cnt != k and j < n) {j++;cnt++;}
                if(cnt >= k) break;
            }
            if(cnt >= k){
                ans = md;
                e = md - 1;
            }else s = md + 1;
        }
        return ans;
    }
};