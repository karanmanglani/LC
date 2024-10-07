class Solution {
public:
    int minLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        stack<char> stk;

        for (char ch : s) {
            if (!stk.empty() && 
                ((stk.top() == 'A' && ch == 'B') || (stk.top() == 'C' && ch == 'D'))) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }

        return stk.size();
    }
};
