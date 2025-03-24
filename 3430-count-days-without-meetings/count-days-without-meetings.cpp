class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        cin.tie(0) -> sync_with_stdio(false);
        sort(meetings.begin(),meetings.end());
        int l = meetings[0][0], r= meetings[0][1];
        vector<pair<int,int>> v;
        for(int i = 1;i < meetings.size();i++){
            if(meetings[i][0] <= r){
                r = max(r,meetings[i][1]);
            }else{
                v.push_back({l,r});
                l = meetings[i][0];
                r = meetings[i][1];
            }
        }
        if(v.size() == 0 || l != v[v.size() - 1].first)v.push_back({l,r});
        int tr = 0;
        for(auto i : v){
            l = i.first;
            r = i.second;
            if(l <= days){
                tr += min(r,days) - l + 1;
            }
        }
        return days-tr;        
    }
};