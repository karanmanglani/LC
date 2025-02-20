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
    int rangeSumBST(TreeNode* root, int low, int high) {
        cin.tie(0) -> sync_with_stdio(0);
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int y = x -> val;
            if(y < low) {
                if(x ->  right != NULL) q.push(x -> right);
            }else if(y >= low and y <= high) {
                ans += y;
                if(x -> right != NULL) q.push(x -> right);
                if(x -> left != NULL) q.push(x -> left);
            }else {
                if(x -> left != NULL) q.push(x -> left);
            }
        }
        return ans;
    }
};