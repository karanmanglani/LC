class Solution {
public:
    int ladderLength(string s, string t, vector<string>& lst) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        set<string> st;
        for(auto i : lst)st.insert(i);
        queue<pair<string,int>> q;
        q.push({s,1});
        int ans = 0;
        while(!q.empty()){
            auto front = q.front();q.pop();
            int dist = front.second;
            string k = front.first;
            if(k == t) return dist;
            for(int i = 0;i < k.size();i++){
                for(int j = 0;j < 26;j++){
                    char x = 'a' + j;
                    if(x != k[i]){
                        string nk = k;
                        nk[i] = x;
                        if(st.find(nk) != st.end()){
                            q.push({nk,dist+1});
                            st.erase(nk);
                        }
                    }
                }
            }
        }
        return 0;
    }
};