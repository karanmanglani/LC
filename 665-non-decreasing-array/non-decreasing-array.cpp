typedef long long int lli;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(0);
        bool fnd = false;
        bool ans = true,ans1 = true;;
        vector<int> a = nums;
        for(lli i = 1;i < (lli)nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(fnd) ans = false;
                else {nums[i] = nums[i-1];fnd = true;}
            }
        }
        fnd = false;
        vector<int> b = nums;
        sort(b.begin(),b.end());
        if(nums != b) ans = false;
        for(lli i = 1;i < (lli)a.size();i++){
            if(a[i-1] > a[i]){
                if(fnd) ans1 = false;
                else {a[i-1] = a[i];fnd = true;}
            }
        }
        vector<int> c = a;
        sort(c.begin(),c.end());
        if(a != c) ans1 = false;
        return (ans || ans1);
    }
};