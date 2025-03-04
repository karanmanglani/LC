typedef long long int lli;
class Solution {
public:
    bool checkPowersOfThree(int n) {
        lli x = n;
        vector<bool> used(65,false); 
        while(x){
            if(x % 3 == 0){
                lli y = 3;
                lli cnt = 1;
                while(x % y == 0) {y *= 3;cnt++;}
                y /= 3;
                cnt--;
                if(used[cnt]) return false;
                else {
                    x -= y;
                    used[cnt] = true;
                }
            }else if(x % 3 == 1){
                if(used[0]) return false;
                used[0] = true;
                x--;

            }else {
                return false;
            }
        }
        return true;
    }
};