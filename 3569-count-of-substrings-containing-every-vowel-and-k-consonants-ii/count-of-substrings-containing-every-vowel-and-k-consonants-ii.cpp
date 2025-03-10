typedef long long int lli;
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<lli> vwls(5,0);
        lli l = 0, r = 0, ans = 0, extraLeft = 0;
        while(r < word.size()){
            if(word[r]=='a') vwls[0]++;
            if(word[r]=='e') vwls[1]++;
            if(word[r]=='i') vwls[2]++;
            if(word[r]=='o') vwls[3]++;
            if(word[r]=='u') vwls[4]++;
            while(l <= r && ((r-l+1) - (vwls[0]+vwls[1]+vwls[2]+vwls[3]+vwls[4])) > k){
                if(word[l]=='a') vwls[0]--;
                if(word[l]=='e') vwls[1]--;
                if(word[l]=='i') vwls[2]--;
                if(word[l]=='o') vwls[3]--;
                if(word[l]=='u') vwls[4]--;
                l++;
                extraLeft = 0;
            }
            if(vwls[0] && vwls[1] && vwls[2] && vwls[3] && vwls[4] && ((r-l+1) - (vwls[0]+vwls[1]+vwls[2]+vwls[3]+vwls[4])) == k){
                while(l < r && ((word[l]=='a' && vwls[0]>1) || (word[l]=='e' && vwls[1]>1) || (word[l]=='i' && vwls[2]>1) || (word[l]=='o' && vwls[3]>1) || (word[l]=='u' && vwls[4]>1))){
                    extraLeft++;
                    if(word[l]=='a') vwls[0]--;
                    if(word[l]=='e') vwls[1]--;
                    if(word[l]=='i') vwls[2]--;
                    if(word[l]=='o') vwls[3]--;
                    if(word[l]=='u') vwls[4]--;
                    l++;
                }
                ans += (extraLeft + 1);
            }
            r++;
        }
        return ans;
    }
};
