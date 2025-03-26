class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> a;
        for(auto i : grid){
            for(auto j : i) a.push_back(j);
        }
        int n = a.size(),md = -1;
        int ans = 0;
        for(auto i : a){
            if(md == -1) md = i % x;
            else {
                if(i % x != md) return -1;
            }
        }
        nth_element(a.begin(), a.begin() + n / 2, a.end());
        md = a[n/2];
        for(auto i : a){
            ans += abs(i - md)/x;
        }
        return ans;
    }
};