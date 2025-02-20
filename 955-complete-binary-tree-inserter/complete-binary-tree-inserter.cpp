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
class CBTInserter {
public:
    TreeNode* rt;
    CBTInserter(TreeNode* root) {
        rt = root;
    }

    int insert(int val) {
        queue<TreeNode*> q;
        q.push(rt);
        TreeNode* node = new TreeNode(val);
        int ans = rt->val;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x -> left == NULL) {
                x -> left = node;
                ans = x -> val;
                break;
            }else if(x -> right == NULL) {
                x -> right = node;
                ans = x -> val;
                break;
            }else {
                q.push(x -> left);
                q.push(x -> right);
            }
        }
        return ans;
    }
    
    TreeNode* get_root() {
        return rt;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */