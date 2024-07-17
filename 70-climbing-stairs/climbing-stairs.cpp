class Solution {
public:

    int climbStairs(int n) {
        // bottom Up + space optimization
        int prev = 1,prePrev = 1;
        int curr;
        for(int i = 2; i <= n; i++) {
            curr = prev + prePrev;
            prePrev = prev;
            prev = curr;
        }



        return prev;
    }
};