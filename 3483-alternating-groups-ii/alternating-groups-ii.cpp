class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        cin.tie(0) -> sync_with_stdio(false);
        int n = colors.size();
        int ans = 0;
        int l = 0;
        
        for (int r = 0; r < n + k - 1; ++r) {
            if (r > 0 && colors[r % n] == colors[(r - 1) % n]) {
                l = r;  
            }
            
            if (r - l + 1 >= k) {
                ans++;  
            }
        }
        
        return ans;
    }
};