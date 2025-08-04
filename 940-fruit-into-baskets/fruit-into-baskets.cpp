class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(),a = 0,b = 1,i = 0, j = 0;
        while(j + 1 < n && fruits[j] == fruits[i]) {j++;b = j;}
        int mx = j - i + 1;
        while(j < n){
            while(j+1 < n && (fruits[j+1] == fruits[a] || fruits[j+1] == fruits[b])){
                j++;
                if(fruits[j] == fruits[a]){
                    a = b;
                    b = j;
                }
            }
            mx = max(mx,j-i+1);            
            j++;
            i = b;
            a = i;
            b = j;
        }
        return mx;
    }
};