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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result; 
        //Iterative Method using 1 stack
        
        // stack<TreeNode*> s;
        // TreeNode* current = root;
        // TreeNode* lastVisited = nullptr; 
        
        // while (!s.empty() || current != nullptr) {
            
        //     while (current != nullptr) {
        //         s.push(current);
        //         current = current->left;
        //     }
            
            
        //     TreeNode* topNode = s.top();
            
            
        //     if (topNode->right != nullptr && lastVisited != topNode->right) {
        //         current = topNode->right;
        //     } else {
                
        //         result.push_back(topNode->val);
        //         s.pop();
        //         lastVisited = topNode; 
        //     }
        // }
        
        // Iterative Method using 2 stacks
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp);
            if(temp -> left != NULL) st1.push(temp -> left);
            if(temp -> right != NULL) st1.push(temp -> right);
        }

        while(!st2.empty()){
            TreeNode* temp = st2.top();
            result.push_back(temp -> val);
            st2.pop();
        }

        return result;

    }
};