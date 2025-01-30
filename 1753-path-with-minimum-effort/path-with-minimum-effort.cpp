typedef long long int lli;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        lli m = heights.size(),n=heights[0].size();
        if(m == 1 and n == 1) return 0;
        vector<vector<lli>> dist(heights.size() , vector<lli> (heights[0].size(),LLONG_MAX));
        set<pair<lli,pair<lli,lli>>> st;
        st.insert({0,{0,0}});
        dist[0][0] = 0;
        while(st.size() > 0){
            auto it = *(st.begin());
            lli i = it.second.first,j = it.second.second, dst = it.first;
            st.erase(it);
            lli ni = i-1, nj = j;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n){
                lli diff = abs(heights[i][j] - heights[ni][nj]);
                if(max(diff,dst) < dist[ni][nj]){
                    st.erase({dist[ni][nj],{ni,nj}});
                    dist[ni][nj] = max(diff,dst);
                    st.insert({dist[ni][nj],{ni,nj}});
                }
            }
            ni = i + 1;nj = j;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n){
                lli diff = abs(heights[i][j] - heights[ni][nj]);
                if(max(diff,dst) < dist[ni][nj]){
                    st.erase({dist[ni][nj],{ni,nj}});
                    dist[ni][nj] = max(diff,dst);
                    st.insert({dist[ni][nj],{ni,nj}});
                }
            }
            ni = i;nj = j-1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n){
                lli diff = abs(heights[i][j] - heights[ni][nj]);
                if(max(diff,dst) < dist[ni][nj]){
                    st.erase({dist[ni][nj],{ni,nj}});
                    dist[ni][nj] = max(diff,dst);
                    st.insert({dist[ni][nj],{ni,nj}});
                }
            }

            ni = i;nj = j+1;
            if(ni >= 0 and nj >= 0 and ni < m and nj < n){
                lli diff = abs(heights[i][j] - heights[ni][nj]);
                if(max(diff,dst) < dist[ni][nj]){
                    st.erase({dist[ni][nj],{ni,nj}});
                    dist[ni][nj] = max(diff,dst);
                    st.insert({dist[ni][nj],{ni,nj}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};