class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // By multiset
        // multiset<int> st;
        // vector<int> ans;
        // for(int i = 0;i < nums.size();i++){
        //     st.insert(nums[i]);
        //     if(i >= k) st.extract(nums[i-k]);
        //     if(i >= k-1) ans.push_back(*prev(st.end()));
        // }

        // Dequeue Optimisation
        vector<int> ans;
        deque<int> q;
        for(int i = 0;i < nums.size(); i++){
            while(!q.empty() and nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(q.front() == i-k) q.pop_front();
            if(i >= k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};