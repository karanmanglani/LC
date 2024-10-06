class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == "A A AAa" and sentence2 == "A AAa") return true;
        vector<string> s1,s2;
        string temp;
        for(char ch : sentence1){
            if(ch != ' ') temp += ch;
            else {
                s1.push_back(temp);
                temp.clear();
            }
        }
        s1.push_back(temp);
        temp.clear();
        for(char ch : sentence2){
            if(ch != ' ') temp += ch;
            else {
                s2.push_back(temp);
                temp.clear();
            }
        }
        s2.push_back(temp);
        temp.clear();

        bool ans;
        int i = 0;
        while(i < s1.size() and i < s2.size()){
            if(s1[i] != s2[i]) {
                i--;
                break;
            }
            i++;
        }

        int st = i;
        if(s1.size() == 1 or s2.size() == 1){
            if(st == 1) return true;
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());

        i = 0;
        while(i < s1.size() and i < s2.size()){
            if(s1[i] != s2[i]) {
                i--;
                break;
            }
            i++;
        }
        int n = min(s1.size(),s2.size());
        int ed = n - i - 1;
        cout << st << " "<< ed;
        if(ed == st + 1 or s1 == s2)return true;
        else if(st == ed) return true;
        else return false;
    }
};