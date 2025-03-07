class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else if(nums[i] + nums[l] + nums[r] > 0) r--;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    l++;
                    while(nums[l] == nums[l-1] and l < r)l++;
                }
            }
        }
        return ans;
    }
};