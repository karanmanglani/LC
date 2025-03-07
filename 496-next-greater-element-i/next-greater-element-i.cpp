class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> idx(1e4+1,-1);
        int n = nums2.size();
        for(int i = 0;i < n;i++){
            idx[nums2[i]] = i;
        }
        vector<int> ng(n,-1);
        stack<int> st;
        for(int i = n-1;i >= 0;i--){
            while(!st.empty() and st.top() <= nums2[i]) st.pop();
            if(!st.empty()) ng[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i : nums1){
            ans.push_back(ng[idx[i]]);
        }
        return ans;
    }
};