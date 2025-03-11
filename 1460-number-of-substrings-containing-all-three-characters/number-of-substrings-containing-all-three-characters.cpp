class Solution {
public:
    int numberOfSubstrings(string s) {
        cin.tie(0) -> sync_with_stdio(false);
        int ans = 0;
        vector<int> cnt(3,0);
        int l = 0,r = 0, n = s.size();
        bool flag = true;
        while(r < n){
            if(flag and s[r] == 'a') cnt[0]++;
            if(flag and s[r] == 'b') cnt[1]++;
            if(flag and s[r] == 'c') cnt[2]++;
            if(l < r and cnt[0] && cnt[1] && cnt[2]){
                ans += n-r;
                if(s[l] == 'a') cnt[0]--;
                if(s[l] == 'b') cnt[1]--;
                if(s[l] == 'c') cnt[2]--;
                l++;
                flag = false;
            }else {
                r++;
                flag = true;
            }
        }
        return ans;
    }
};