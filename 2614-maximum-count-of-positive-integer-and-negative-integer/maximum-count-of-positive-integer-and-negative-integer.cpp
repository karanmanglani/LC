class Solution {
public:
    int maximumCount(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        int lnn = -1, fp = -1,n = nums.size();
        int s = 0,e = n-1;
        while(s <= e){
            int md = s + (e-s)/2;
            if(nums[md] < 0) {
                lnn = md;
                s = md + 1;
            }else e = md -1;
        }
        s = 0;e = n-1;
        while(s <= e){
            int md = s + (e-s)/2;
            if(nums[md] > 0){
                fp = md;
                e = md - 1;
            }else s = md + 1;
        }
        int p = 0,ne = 0;
        if(lnn != -1) ne = lnn+1;
        if(fp != -1)  p = n - fp;
        return max(ne,p);

    }
};