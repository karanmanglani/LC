typedef long long int lli;

class Solution {
public:
    pair<vector<bool>, pair<vector<lli> , vector<lli>>> primeArr(lli n,lli left) { // TC -> O(NloglogN)
        vector<bool> arr(n + 1, true);
        vector<lli> spf(n + 1, n);
        vector<lli> ptn;
        spf[1] = 1;
        arr[0] = false;
        arr[1] = false;
        for(lli i = 2; i <= n; i++) {
            if(arr[i]) {
                if(i >= left and i <= n) ptn.push_back(i);
                spf[i] = i;
                for(lli j = i * i; j <= n; j += i) {
                    spf[j] = min(i, spf[j]);
                    arr[j] = false;
                }
            }
        }
        return {arr, {spf,ptn}};
    }

    vector<int> closestPrimes(int left, int right) {
        cin.tie(0) -> sync_with_stdio(false);
        vector<lli> arr = primeArr(right,left).second.second;
        vector<int> ans(2);
        ans[0] = 0; ans[1] = INT_MAX;
        lli i = 0,j = 1;
        for(;j <arr.size();j++){
            if((arr[j] - arr[i]) < (ans[1] - ans[0])) {ans[1] = arr[j] ; ans[0] = arr[i]; }
            i++;
        }
        if(ans[0] == 0) return {-1,-1};
        return ans;
    }
};