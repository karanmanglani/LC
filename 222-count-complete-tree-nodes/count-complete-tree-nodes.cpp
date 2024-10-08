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

    int find(TreeNode* root , int lvl){
        if(root -> left == NULL and root -> right == NULL) return lvl;
        return find(root -> left, lvl + 1);
    }

    void solve(TreeNode* root , int& nf , bool& found,int lvl,int mxLvl){
        if(found) return ;
        if(!found and lvl == mxLvl) {
            found = true;
            return ;
        }
        if(root -> right){
            solve(root -> right, nf,found, lvl+ 1, mxLvl);
            if(found) return ;
        }
        if (!(root -> right)) nf++;
        if(root -> left){
            solve(root -> left, nf,found, lvl+ 1, mxLvl);
            if(found) return ;
        }
        if (!(root -> left)) nf++;
    }

    int countNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(root == NULL) return 0;
        int notFound = 0,mxLvl = 0;
        mxLvl = find(root,0);
        bool found = false;
        solve(root,notFound,found,0,mxLvl);
        return (pow(2,mxLvl + 1) - 1 - notFound);
        
    }
};