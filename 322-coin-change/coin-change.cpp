class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
        cin.tie(0) -> sync_with_stdio(false);
        if(amount == 0) return 0;
        vector<int> arr(amount+1,-1);
        arr[0] = 0;
        for(int i = 0;i <= amount;i++){
            if(arr[i] != -1){
                for(auto it : coins){
                    if(it<= amount - i){
                        arr[i + it] = (arr[i + it] == -1) ? 1 + arr[i] : min(arr[i+it], 1 + arr[i]);
                    }
                }
            }
        }
        return arr[amount];
    }
};