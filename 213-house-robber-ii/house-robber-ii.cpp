class Solution {
public:
    int rob(vector<int>& nums) {
        cin.tie(0) -> sync_with_stdio(0);
        if(nums.size() <= 3) return *max_element(nums.begin(),nums.end());
        vector<int> a,b;
        int n = nums.size();
        for(int i = 1;i < n;i++) a.push_back(nums[i]);
        for(int i = 0;i < n - 1;i++) b.push_back(nums[i]);
        int c = a[0], d = max(a[0], a[1]);
        int ans = INT_MIN,anss = INT_MIN;
        for(int i = 2;i < a.size();i++){
            ans = max(d, a[i] + c);
            if(c > d) d = c;
            c = d; d = ans;
        }
        c = b[0];d = max(b[0],b[1]);
        for(int i = 2;i < b.size();i++){
            anss = max(d, b[i] + c);
            if(c > d) d = c;
            c = d; d = anss;
        }
        return max(ans,anss);
    }
};