class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int b = 0, m = 0;
        for (char c : s) {
            if (c == '[') b++;
            else b--;
            if (b < 0) {
                m = max(m, -b);
            }
        }
        return (m + 1) / 2;
    }
};
