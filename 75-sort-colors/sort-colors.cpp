class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  s = 0, i = 0 , e = nums.size() - 1;
        while(i <= e){
            if(nums[i] == 0) swap(nums[i++],nums[s++]);
            else if(nums[i] == 2) swap(nums[i],nums[e--]);
            else i++;
        }
    }
};