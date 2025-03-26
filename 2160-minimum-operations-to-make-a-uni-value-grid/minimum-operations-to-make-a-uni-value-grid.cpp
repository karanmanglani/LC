class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            for (int num : row)
                nums.push_back(num);
        }
        
        // Check feasibility: All numbers must have the same remainder modulo x.
        int remainder = nums[0] % x;
        for (int num : nums) {
            if (num % x != remainder)
                return -1;
        }
        
        int n = nums.size();
        // Use nth_element to get the median in average-case O(n) time.
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];
        
        long long operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
