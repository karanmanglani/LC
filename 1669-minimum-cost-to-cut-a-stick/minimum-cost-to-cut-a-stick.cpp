class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> nc;
        nc.push_back(0);
        for(auto i : cuts) nc.push_back(i);
        nc.push_back(n);
        sort(nc.begin(),nc.end());
        cuts = nc;
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size() ,-1));
        auto f = [&](int i , int j, auto &&F){
            if(i + 1 >= j) return 0;
            int sz = cuts[j] - cuts[i];
            if(dp[i][j] != -1) return dp[i][j];
            dp[i][j] = INT_MAX;
            for(int k = i+1;k < j;k++){
                dp[i][j] = min(dp[i][j], sz + F(i,k,F) + F(k,j,F));
            }
            return dp[i][j];
        };
        return f(0,cuts.size()-1,f);
    }
};