class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        cin.tie(0) -> sync_with_stdio(false);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt = 0;
        int i = 0, j = 0;
        while(i < g.size() and j < s.size()){
            while(j < s.size() and s[j] < g[i]) j++;
            if(j < s.size() and g[i] <= s[j]) cnt++;
            i++;
            j++;
        }
        return cnt;
    }
};