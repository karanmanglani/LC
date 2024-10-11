class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> events;
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i});
            events.push_back({times[i][1], -i-1}); 
        }
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> freeChairs;
        for (int i = 0; i < n; ++i) freeChairs.push(i);
        vector<int> assigned(n, -1);
        for (auto& e : events) {
            if (e.second >= 0) { 
                int c = freeChairs.top();
                freeChairs.pop();
                assigned[e.second] = c;
                if (e.second == targetFriend) return c;
            } else { 
                freeChairs.push(assigned[-e.second-1]);
            }
        }
        return -1;
    }
};
