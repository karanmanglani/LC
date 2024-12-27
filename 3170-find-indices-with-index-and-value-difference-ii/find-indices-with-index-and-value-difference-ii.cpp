class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int leftMin = 0, leftMax = 0;
        for(int i = indexDifference; i < nums.size(); i++) {
            if (nums[leftMin] > nums[i - indexDifference]) leftMin = i - indexDifference;
            else if (nums[leftMax] < nums[i - indexDifference]) leftMax = i - indexDifference;
            
            if (abs(nums[i] - nums[leftMin]) >= valueDifference) return {leftMin, i};
            if (abs(nums[i] - nums[leftMax]) >= valueDifference) return {leftMax, i};
        }
        return {-1, -1};
    }
};