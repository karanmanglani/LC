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
    int mx = INT_MIN;
    bool foundPos = false;

    int mps(TreeNode* root){
        if(root == NULL) {
            return 0;
        }
        
        int left = max(0,mps(root -> left));
        int right = max(0,mps(root -> right));
        int curr = left + right + root -> val;
        mx = max(curr , mx);
        return (root -> val + max(left,right));
    }

    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root == NULL) return 0;
        mx = root -> val;
        mps(root);
        return mx;
    }
};