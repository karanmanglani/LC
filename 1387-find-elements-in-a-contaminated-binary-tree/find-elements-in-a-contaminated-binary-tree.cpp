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
    // map<int,int> pres;
    TreeNode* rt;
    void setValue(TreeNode* root, int x){
        root -> val = x;
        // pres[x] = 1;
        if(root -> left != NULL) setValue(root -> left, 2*x + 1);
        if(root -> right != NULL) setValue(root -> right , 2*x + 2);
    }

    FindElements(TreeNode* root) {
        rt = root;
        setValue(root,0);
    }
    
    bool find(int target) {
        bool fnd = false;
        queue<TreeNode*> q;
        q.push(rt);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x -> val > target) break;
            else if(x -> val == target) {fnd = true;break;}
            if(x-> left) q.push(x -> left);
            if(x -> right) q.push(x -> right);
        }
        return fnd;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */