class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        vector<int> stack;
        int maxWidth = 0;

        for (int i = 0; i < n; i++) {
            if (stack.empty() || nums[stack.back()] > nums[i]) {
                stack.push_back(i);
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) {
                maxWidth = max(maxWidth, j - stack.back());
                stack.pop_back();
            }
        }

        return maxWidth;
    }
};
