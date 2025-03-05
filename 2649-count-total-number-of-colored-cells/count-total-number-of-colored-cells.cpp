class Solution {
public:
    long long coloredCells(int n) {
        cin.tie(0) -> sync_with_stdio(false);
        long long int ans = 1 + 2LL*n*(n-1);
        return ans;
    }
};