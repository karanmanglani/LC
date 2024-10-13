#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int k = nums.size(), l = INT_MAX, r = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> idx(k, 0);
        
        for (int i = 0; i < k; ++i) {
            pq.push({nums[i][0], i});
            r = max(r, nums[i][0]);
        }

        vector<int> res = {pq.top().first, r};

        while (true) {
            auto [val, i] = pq.top();
            pq.pop();
            l = val;

            if (r - l < res[1] - res[0]) res = {l, r};

            if (++idx[i] == nums[i].size()) break;
            
            pq.push({nums[i][idx[i]], i});
            r = max(r, nums[i][idx[i]]);
        }
        
        return res;
    }
};
