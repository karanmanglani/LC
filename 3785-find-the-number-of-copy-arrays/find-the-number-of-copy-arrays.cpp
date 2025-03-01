class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<int> d;
        int n = original.size();
        for(int i = 1;i < n;i++){
            d.push_back(original[i] - original[i-1]);
        }
        int sum = 0;
        int mn = bounds[0][0], mx = bounds[0][1];
        for(int i = 1;i < n;i++){
            sum += d[i-1];
            int tmn = bounds[i][0] - sum,tmx = bounds[i][1] - sum;
            mn=max(mn,tmn);
            mx = min(mx,tmx);
        }
        return max(mx - mn + 1,0);
    }
};