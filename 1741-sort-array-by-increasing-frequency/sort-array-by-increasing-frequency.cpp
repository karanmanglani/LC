class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> x;
        for (int num : nums) {
            x[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (x[a] != x[b]) {
                return x[a] < x[b];
            }
            return a > b;
        });

        return nums;
    }
};