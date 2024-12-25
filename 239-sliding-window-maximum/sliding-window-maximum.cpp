class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        multiset<int> st;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            st.insert(nums[i]);
            if(i >= k) st.extract(nums[i-k]);
            if(i >= k-1) ans.push_back(*prev(st.end()));
        }
        return ans;
    }
};