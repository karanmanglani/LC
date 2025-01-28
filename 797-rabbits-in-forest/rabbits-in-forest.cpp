typedef long long int lli;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        cin.tie(0) -> sync_with_stdio(0);
        unordered_map<lli,lli> fc;
        lli ans = 0;
        for(auto i : answers) {
            fc[i]++;
        }
        for(auto i : fc){
            if(i.second < (i.first+1)) ans += i.first + 1;
            else {
                lli x = i.second / (i.first + 1);
                x *= (i.first + 1);
                ans += x;
                if(x != i.second) ans += i.first + 1;
            }
        }
        return ans;
    }
};