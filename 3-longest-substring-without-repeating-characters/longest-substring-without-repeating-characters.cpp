class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> fc(256,0);
        int n = s.size();
        int l = 0,r = 0, ans = 0;
        while(r < n){
            fc[(s[r])]++;
            if(fc[(s[r])] > 1){
                while(l < r and fc[(s[r])] > 1){
                    fc[(s[l])]--;
                    l++;
                }
                ans = max(ans,r-l+1);
            }else {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};