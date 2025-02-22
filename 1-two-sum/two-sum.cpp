class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<int> ans(2,-1);
        int l = 0, r = nums.size() - 1, n = nums.size();
        vector<pair<int,int>> a(n);
        for(int i = 0;i < n;i++) a[i] = {nums[i],i};
        sort(a.begin(),a.end());
        while(l < r){
            int sum = a[l].first + a[r].first;
            if(sum == target) {ans[0] = a[l].second;ans[1] = a[r].second;break;}
            else if(sum > target) r--;
            else l++;
        }
        return ans;
    }
};