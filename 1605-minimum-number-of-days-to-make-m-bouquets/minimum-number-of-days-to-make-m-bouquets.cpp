typedef long long int lli;
class Solution {
public:

    bool chk(vector<int> a, lli md, int m , int k){
        lli n = a.size();
        lli b = 0;
        lli i = 0;
        lli j = i;
        while(j < n){
            if(a[j] <= md){
                if(j - i + 1 == k) {
                    b++;
                    i = j+1;
                }
                j++;
            }else{
                i = j+1;
                j++;
            }
            if(b == m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        lli ans = 1e10;
        lli s = 0, e = 1e10;
        while(s <= e){
            lli md = s + (e-s)/2;
            if(chk(bloomDay, md,m,k)){
                ans = md;
                e = md - 1;
            }else s = md + 1;
        }
        return ans != 1e10 ? ans : -1;
    }
};