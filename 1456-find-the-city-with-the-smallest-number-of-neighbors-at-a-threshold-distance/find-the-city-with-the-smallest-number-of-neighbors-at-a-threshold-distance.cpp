typedef long long int lli;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        cin.tie(0) -> sync_with_stdio(0);
        vector<vector<lli>> mtx(n,vector<lli>(n,1e5));
        for(auto i : edges){
            mtx[i[0]][i[1]] = i[2];
            mtx[i[1]][i[0]] = i[2];
        }
        for(lli i = 0;i < n;i++) mtx[i][i] = 0;

        for(lli v = 0;v < n;v++){
            for(lli i = 0;i < n;i++){
                for(lli j = 0;j < n;j++){
                    if(i == j) continue;
                    mtx[i][j] = min(mtx[i][j] , (mtx[i][v] + mtx[v][j]));
                }
            }
        }

        lli ans = 0, cm = n;
        for(lli i = 0;i < n;i++){
            lli ct = 0;
            for(lli j = 0;j < n;j++){
                if(i == j) continue;
                if(mtx[i][j] <= d) ct++;
            }
            if(ct <= cm) {ans = i;cm = ct;}
        }

        return ans;
    }
};