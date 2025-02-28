class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum=0;
        vector<int> l,r;
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()/2)l.push_back(nums[i]);
            else r.push_back(nums[i]);
            sum+=nums[i];
        }
        int x=sum/2;
        int n=nums.size()/2;
        vector<vector<int>> left(n+1),right(n+1);
        left[0].push_back(0); right[0].push_back(0);
        for(int i=0;i<(1<<n);i++){
            int x= __builtin_popcount(i),tot1=0,tot2=0;
            for(int j=0;j<15;j++){
                if((i&(1<<j))){
                    tot1+=l[j];
                    tot2+=r[j];
                }
            }
            left[x].push_back(tot1);
            right[x].push_back(tot2);
        }
        int ans=1e9;
        for(int i=0;i<=n;i++){
            sort(right[n-i].begin(),right[n-i].end());
            for(auto j: left[i]){
                int y=n-i;
                int k= lower_bound(right[y].begin(),right[y].end(),x-j)-right[y].begin();
                if(k!=right[y].size()){
                    int tot1=j+right[y][k];
                    int tot2=sum-tot1;
                    ans=min(ans,abs(tot2-tot1));
                }
                if(k!=0){
                    int tot1=j+right[y][k-1];
                    int tot2=sum-tot1;
                    ans=min(ans,abs(tot2-tot1));
                }
            }
        }
        return ans;
    }
};