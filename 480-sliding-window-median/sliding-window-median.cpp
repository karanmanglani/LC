typedef long long int lli;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        multiset<lli> a,b;
        vector<double> ans;
        auto balance = [&](){
            if(a.size()> b.size()+1){
                b.insert(*a.rbegin());
                a.erase(prev(a.end()));
            }else if(a.size() < b.size()){
                a.insert(*b.begin());
                b.erase(b.begin());
            }
        };

        for(lli i = 0;i < nums.size();i++){
            if(a.empty() || nums[i] <= *a.rbegin()) a.insert(nums[i]);
            else b.insert(nums[i]);
            balance();

            if(i >= k){
                lli x = nums[i-k];
                if(x <= *a.rbegin()) a.extract(x);
                else b.extract(x);
                balance();
            }

            if(i >= k-1){
                ans.push_back(k&1 ? *a.rbegin() : ((double)*a.rbegin() + (double)*b.begin())/2.0);
            }
        }
        return ans;
    }
};