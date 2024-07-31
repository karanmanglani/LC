class Solution {
public:

    int solve(vector<int> nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        int three = nums[n-1], two = nums[n-2],one = nums[n-3] + nums[n-1];
        if(n == 3){
            return max(one , max(two , three));
        }

        for(int i = n-4; i > 0; i--){
            int curr = nums[i] + max(two, three);
            three = two;
            two = one;
            one = curr;
        }

        return max(one , nums[0] + max(two, three));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> a(nums.begin(),nums.end() -1);
        vector<int> b(nums.begin() + 1, nums.end());

        int c = solve(a);
        int d = solve(b);
        return max(c , d);
    }
};