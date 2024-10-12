class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<pair<int, int>> events;
        
        for (auto& itv : intervals) {
            events.push_back({itv[0], 1});
            events.push_back({itv[1] + 1, -1});
        }
        
        sort(events.begin(), events.end());
        
        int maxGrps = 0, currGrps = 0;
        
        for (auto& e : events) {
            currGrps += e.second;
            maxGrps = max(maxGrps, currGrps);
        }
        
        return maxGrps;
    }
};
