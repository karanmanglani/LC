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

    int cnt(TreeNode* root){
        if(root == NULL) return 0;
        return (1 + cnt(root -> left) + cnt(root -> right));
    }

    bool isCBT(TreeNode* root , int idx, int cnt){
        if(root == NULL) return true;
        if(idx >= cnt) return false;
        else return (isCBT(root -> left, 2*idx + 1 , cnt) && isCBT(root -> right,2*idx + 2 , cnt));
    }

    bool isCompleteTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int num = cnt(root);
        return isCBT(root , 0,num);
    }
};