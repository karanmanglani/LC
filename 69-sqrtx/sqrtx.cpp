class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        long long int  ans = x;
        while(e - s>=0){
            long long int mid = s + (e-s)/2;
            if(mid * mid <= x){
                ans = mid;
                s = mid + 1;
            }else {
                e = mid - 1;
            }
        }
        return ans;
    }
};