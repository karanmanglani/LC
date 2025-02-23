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



    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        cin.tie(0) -> sync_with_stdio(false);
        map<int,int> mp1,mp2;
        for(int i = 0;i < preorder.size();i++) {mp1[preorder[i]] = i;mp2[postorder[i]] = i;}
        int n = preorder.size();
        vector<bool> vis(n,false);
        TreeNode* root = new TreeNode(preorder[0]);
        vis[0] = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            int ni = mp1[curr -> val] + 1;
            if(ni < n and !vis[ni]){
                TreeNode* lft = new TreeNode(preorder[ni]);
                curr -> left = lft;
                vis[ni] = true;
                q.push(lft);
            }

            ni = mp2[curr -> val] - 1;
            if(ni >= 0 and !vis[mp1[postorder[ni]]]){
                TreeNode* rgt = new TreeNode(postorder[ni]);
                curr -> right = rgt;
                vis[mp1[postorder[ni]]] = true;
                q.push(rgt);
            }
        }
        return root;
    }
};