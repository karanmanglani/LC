class Solution {
public:
    int uniquePaths(int m, int n) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<int> column(n,1);
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                column[j] += (j == 1) ? 1 : column[j-1];
            }
        }
        return column[n-1];
    }
};