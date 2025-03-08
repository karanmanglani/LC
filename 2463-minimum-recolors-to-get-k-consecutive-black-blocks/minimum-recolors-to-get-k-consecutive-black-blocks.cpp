class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        cin.tie(0) -> sync_with_stdio(false);
        int b = 0,w=0;
        int i = 0;
        int n = blocks.size();
        for(;i < k;i++){
            if(blocks[i] == 'W')w++;
            else b++;
        }
        int ans = k-b;
        for(;i < n;i++){
            if(blocks[i-k] == 'W')w--;
            else b--;

            if(blocks[i] == 'W')w++;
            else b++;
            ans = min(ans,k-b);
        }
        return ans;
    }
};