class Solution {
public:

    int climbStairs(int n) {
        // bottom Up + space optimization
        if(n < 3) return n;
        int prev = 2,prePrev = 1;
        int curr = prev + prePrev;
        for(int i = 3; i <= n; i++) {
            curr = prev + prePrev;
            prePrev = prev;
            prev = curr;
        }



        return prev;
    }
};