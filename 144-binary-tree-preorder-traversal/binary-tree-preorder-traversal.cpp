
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

    // void preOrder(TreeNode* root , vector<int> &ans ){
    //     if(root == NULL) return ;
    //     ans.push_back(root->val);
    //     preOrder(root -> left,ans);
    //     preOrder(root -> right, ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        // preOrder(root , ans);
        // Iterative Preorder Traversal
        // Algo --> stack (current -> right -> left)
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp -> val);
            if(temp -> right != NULL)st.push(temp -> right);
            if(temp -> left != NULL)st.push(temp -> left);
        }
        return ans;
    }
};