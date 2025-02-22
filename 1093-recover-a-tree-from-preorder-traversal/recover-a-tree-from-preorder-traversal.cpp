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
        vector<TreeNode*> el(1001);
        int val = traversal[0] - '0';
        int i = 1,n = traversal.size();
        while(i < n and traversal[i] != '-') val = val*10 + traversal[i++] - '0';
        TreeNode* root = new TreeNode(val);
        el[0] = root;
        int d = 0;
        while(i < n){
            if(traversal[i] == '-'){
                d++;
                i++;
            }else{
                TreeNode* curr = el[d-1];
                val = traversal[i++] - '0';
                while(i < n and traversal[i] != '-') val = val*10 + traversal[i++] - '0';
                TreeNode* node = new TreeNode(val);
                el[d] = node;
                d = 0;
                if(curr -> left) curr -> right = node;
                else curr -> left = node;
            }
        }
        return root;
    }
};