class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> x = arr;
        sort(x.begin(),x.end());
        unordered_map<int,int> rk;
        int ctr = 1;
        for(int i : x){
            if(!rk[i]){
                rk[i] = ctr++;
            }
        }

        vector<int> ans;
        for(int i : arr){
            ans.push_back(rk[i]);
        }
        return ans;
    }
};