class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() and st.top() <= nums[i]) st.pop();
            st.push(nums[i]);
        }
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() and st.top() <= nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};