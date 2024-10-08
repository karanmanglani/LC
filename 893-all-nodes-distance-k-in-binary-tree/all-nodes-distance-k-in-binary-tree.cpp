/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans;
        if(!root) return ans;
        unordered_map<TreeNode* , TreeNode*> p;
        unordered_map<TreeNode* , bool> v;
        p[root] = NULL;
        // Map Parent and find element
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* topNode = q.front();
            q.pop();
            if(topNode -> left){
                q.push(topNode-> left);
                p[topNode -> left] = topNode;
            }
            if(topNode -> right){
                q.push(topNode -> right);
                p[topNode -> right] = topNode;
            }
        }
        // Making Distace from K
        queue<pair<TreeNode*,int>> x;
        x.push({target,0});
        while(!x.empty()){
            auto temp = x.front();
            x.pop();
            TreeNode* topNode = temp.first;
            int dist = temp.second;
            if(dist == k) ans.push_back(topNode -> val);
            v[topNode] = 1;
            if(p[topNode] and !v[p[topNode]]) x.push({p[topNode],dist + 1});
            if(topNode -> left and !v[topNode -> left]) x.push({topNode -> left,dist + 1});
            if(topNode -> right and !v[topNode -> right]) x.push({topNode -> right, dist + 1});
        }

        return ans;
    }
};