class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<int> f(n,0);
        for(int i = 0;i < n;i++){
            int cb = nums[i];
            if(i > 0){
                int tops = f[i-1] - ((i-k >= 0) ? f[i-k] : 0);
                if(tops & 1){
                    cb = cb ^ 1;
                } 
            }
            if(cb == 0){
                if(i+k > n) return -1;
                else f[i]++;
            }

            if(i > 0) f[i] += f[i-1];
            nums[i] =1;
        }
        return f[n-1];
    }
};