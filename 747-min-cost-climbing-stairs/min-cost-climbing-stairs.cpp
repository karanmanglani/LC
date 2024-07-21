class Solution {
public:

    

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Tabulation + space Optimization
        int prev = cost[1];
        int prePrev = cost[0];
        for(int i = 2; i < n ; i++){
            int curr = cost[i] + min(prev , prePrev);
            prePrev = prev;
            prev = curr; 
        }

        return min(prev, prePrev);

    }
};