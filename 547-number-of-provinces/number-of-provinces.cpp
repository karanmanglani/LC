#include<bits/stdc++.h>
typedef long long int lli;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        lli n = isConnected.size();
        vector<bool> vis(n);
        lli ans = 0;
        for(lli i = 0;i < n;i++){
            if(!vis[i]){
                ans++;
                vis[i] = true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int f = q.front();
                    q.pop();
                    for(int j = 0;j < n;j++){
                        if(isConnected[f][j] & !vis[j]){
                            vis[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
            
        }
        return ans;
    }
};