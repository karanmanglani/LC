class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        cin.tie(0) -> sync_with_stdio(false);
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0;i < n;i++) mp[arr[i]] = i;
        vector<vector<int>> dp(n,vector<int> (n,2));
        int ans = 0;
        for(int i = n-2;i >= 0;i--){
            for(int j = n-1;j > i;j--){
                int a = arr[i], b = arr[j], c = a+b;
                int cnt = 2;
                if(mp.find(c) != mp.end()){
                    cnt = 1 + dp[j][mp[c]];
                    ans = max(ans,cnt);
                }
                dp[i][j] = cnt;
            }
        }
        return ans;
    }
};