class Solution {
public:

    string addOne(const string &bst) {
        string str = bst;
        int carry = 1;  
        for (int i = str.size() - 1; i >= 0 && carry; i--) {
            if (str[i] == '1') {
                str[i] = '0';
            } else { 
                str[i] = '1'; 
                carry = 0;
                break;
            }
        }
        if (carry)
            str.insert(str.begin(), '1');
        return str;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        cin.tie(0) -> sync_with_stdio(0);
        sort(nums.begin(),nums.end());
        string ans;
        for(int i = 0;i < nums[0].size();i++) ans += '0';
        int ptr = 0;
        while(ptr < nums.size() and nums[ptr] == ans){
            cout << ans << endl;
            ptr++;
            ans = addOne(ans);
        }
        return ans;
    }
};