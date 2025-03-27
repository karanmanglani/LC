class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = nums.size();
        int mx = 0, mxel = -1;;
        map<int,int> fc;
        for(auto i : nums){
            fc[i]++;
            if(fc[i] > mx) {
                mx = fc[i];
                mxel = i;
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == mxel) cnt++;
            int sz1 = i+1, sz2 = n-sz1;
            if(cnt > sz1/2 and (mx-cnt) > sz2/2) return i;
        }

        return -1;
    }
};