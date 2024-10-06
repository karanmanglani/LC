/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root == NULL) return true;
        bool ans = true;
        map<int,vector<int>> mp; // For level wise storing of the data
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            int lvl = temp.second;
            TreeNode* frontNode = temp.first;
            if(frontNode == NULL){
                mp[lvl].push_back(-200);
                continue;
            }
            mp[lvl].push_back(frontNode -> val);
            q.push({frontNode -> left,lvl + 1});
            q.push({frontNode -> right,lvl + 1});
        }

        for(auto i : mp){
            int a = 0, b = i.second.size() - 1;
            while(b > a){
                if(i.second[a++] != i.second[b--]) {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};