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
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative Inorder Traversal
        vector<int> result;     
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while (current != NULL || !s.empty()) {
            
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            
            
            current = s.top();
            s.pop();
            
            
            result.push_back(current->val);
            
            
            current = current->right;
        }
        
        return result;  
    }
};