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
     TreeNode* deleteNode(TreeNode* root, int key) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root)return NULL;
        if(!root->left&&!root->right&&root->val==key)return NULL;
        if(root->val==key)return helper(root);
        TreeNode*par=root,*curr=root;
        while(root){
            if(root->val==key){
                   if(root->left){
                       auto rMostOfLeft=root->left;
                       while(rMostOfLeft->right){
                        rMostOfLeft=rMostOfLeft->right;
                       }
                       rMostOfLeft->right=root->right;
                       if(par->val>root->val)par->left=root->left;
                       else par->right=root->left;
                   }
                   else{
                      if(par->val>root->val)par->left=root->right;
                       else par->right=root->right;
                   }
                   break;
            }
            if(key>root->val){par=root;root=root->right;}
            else {par=root;root=root->left;}
        }
        return curr;
    }
    TreeNode* helper(TreeNode*root){
         if(!root->left)return root->right;
         if(!root->right)return root->left;
         auto temp=root->left;
         while(temp->right)temp=temp->right;
         temp->right=root->right;
         return root->left;
    }
};