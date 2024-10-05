class Solution {
public:
    bool isPermutation(string s1, string s2){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        bool ans= true;
        vector<int> cnt1(26,0);
        vector<int> cnt2(26,0);
        for(char ch: s1){
            int index = ch - 97;
            cnt1[index]++;
        }
        for(char ch: s2){
            int index = ch - 97;
            cnt2[index]++;
        }
        for(int i = 0; i<26; i++){
            if(cnt1[i] != cnt2[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
    bool checkInclusion(string s1, string s2) {
        bool ans = false;
        if(s1.length() > s2.length()) return false;
        int n = s1.length();
        string s3;
        for(int i = 0; i < n;i++){
            s3.push_back(s2[i]);
        }
        for(int i = 0; i < (s2.length() - n);i++){
            if(isPermutation(s1,s3)){
                ans = true;
                break;
            }else{
                s3.erase(0,1);
                s3.push_back(s2[n+i]);
            }
        }

        if(isPermutation(s1,s3)) ans = true;
        
        return ans;
        
    }
};