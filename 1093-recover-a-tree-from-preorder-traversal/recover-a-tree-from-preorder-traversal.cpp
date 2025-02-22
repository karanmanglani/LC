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
    TreeNode* recoverFromPreorder(string traversal) {
        cin.tie(0) -> sync_with_stdio(0);
        int val = traversal[0] - '0';
        int i = 1,n = traversal.size();
        while(i < n and traversal[i] != '-') val = val * 10 + traversal[i++] - '0';
        TreeNode* root = new TreeNode(val);
        stack<TreeNode*> st;
        st.push(root);
        int d = 0;
        TreeNode* curr = root;
        while(i < n){
            if(traversal[i] == '-'){
                d++;
                i++;
            }else {
                while(st.size() > d) st.pop();
                curr = st.top();
                d = 0;
                val = traversal[i++] - '0';
                while(i < n and traversal[i] != '-') val = val * 10 + traversal[i++] - '0';
                TreeNode* node = new TreeNode(val);
                if(curr -> left != NULL) {curr -> right = node;st.push(node);}
                else {curr -> left = node;st.push(node);}
            }
        }
        return root;
    }
};