class Solution {
public:
 bool allZero(int *arr){
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
         if(s2.length()<s1.length()){
            return false;
        }
        int arr[26] = {0};
        for(int i=0;i<s1.length();i++){
            arr[s1[i]-'a']++;
        }
        int len = s1.length();
        for(int i=0;i<s2.length();i++){
            arr[s2[i]-'a']--;
            if(i-len>=0){
               arr[s2[i-len]-'a']++;
            }
            if(allZero(arr)) {
                return true;
            }
        }
        return false;
    }
};