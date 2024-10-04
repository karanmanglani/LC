typedef long long int lli;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(skill.begin(),skill.end());
        int i = 0, j = skill.size() - 1;
        lli sum = skill[i] + skill[j];
        bool possible = true;
        lli ans = 0;
        while(i < j){
            if(skill[i] + skill[j] == sum){
                ans += skill[i++] * skill[j--];
            }else{
                possible = false;
                break;
            }
        }
        return possible?ans:-1;
        
    }
};