class Solution {
public:
    vector<int> partitionLabels(string s) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> lo(26,-1),ans;
        int n = s.size();
        for(int i =n-1;i>= 0;i--){
            if(lo[s[i] - 'a'] == -1) lo[s[i] - 'a'] = i;
        }
        int l = 0,r= 0,mx = 0;
        while(r < n){
            mx = max(lo[s[r] - 'a'],mx);
            if(r == mx){
                ans.push_back(r-l+1);
                mx = -1;
                l = r+1;
            }
            r++;
        }
        return ans;
    }
}; 