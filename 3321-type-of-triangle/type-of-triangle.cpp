class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> st;
        for(auto i : nums) st.insert(i);
        if(nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) return "none";
        return (st.size() == 1) ? "equilateral" : (st.size() == 2) ? "isosceles" : "scalene" ;
    }
};