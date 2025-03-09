class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        cin.tie(0) -> sync_with_stdio(false);
        int ans = 0;
        int n = colors.size();
        for(int i = 0;i < k-1;i++) colors.push_back(colors[i]);
        int l = 0,r = 1;
        while(l < n and r < colors.size()){
            while(l < n and r < colors.size() and colors[l] == colors[r]) {l++;r++;}
            if(l < n and r < colors.size()) {
                while(r < colors.size()-1 and colors[r+1] != colors[r]) r++;
                int len = r-l+1;
                ans += max(0,len - k + 1);
                l = r + 1;
                r = l + 1;
            }
        }
        return ans;
    }
};