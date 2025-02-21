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
class FindElements {
public:
    map<int,int> pres;
    void setValue(TreeNode* root, int x){
        root -> val = x;
        pres[x] = 1;
        if(root -> left != NULL) setValue(root -> left, 2*x + 1);
        if(root -> right != NULL) setValue(root -> right , 2*x + 2);
    }

    FindElements(TreeNode* root) {
        setValue(root,0);
    }
    
    bool find(int target) {
        return pres[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */