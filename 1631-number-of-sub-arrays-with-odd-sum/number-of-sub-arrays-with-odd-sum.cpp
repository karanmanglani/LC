#define MOD 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        cin.tie(0) -> sync_with_stdio(0);
        int o = 0, e = 1;
        int sum = 0;
        int ans = 0;
        for(auto i : arr){
            sum += i;
            if(sum & 1){
                ans = (ans + e) % MOD;
                o++;
            }else {
                ans = (ans + o) % MOD;
                e++;
            }
        }

        return ans;
    }
};