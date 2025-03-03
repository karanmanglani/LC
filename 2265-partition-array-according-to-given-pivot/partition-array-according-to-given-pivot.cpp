class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> left,right,center;
        for(auto i : nums){
            if(i < pivot) left.push_back(i);
            if(i == pivot) center.push_back(i);
            if(i > pivot) right.push_back(i);
        }
        vector<int> ans;
        for(auto i : left) ans.push_back(i);
        for(auto i : center) ans.push_back(i);
        for(auto i : right) ans.push_back(i);
        return ans;
    }
};