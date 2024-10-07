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
    int widthOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root) return 0;
        int ans = 1;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        int first,last;
        while(!q.empty()){
            int sz = q.size();
            int x = q.front().second;
            for(int i = 0;i < sz;i++){
                long long int cid = q.front().second - x;
                TreeNode* frontNode = q.front().first;
                q.pop();
                if(i == 0) first = cid;
                if(i == sz -1) last = cid;
                if(frontNode -> left) q.push({frontNode -> left,2*cid + 1});
                if(frontNode -> right) q.push({frontNode -> right,2*cid + 2});
            }
            ans = max(last - first + 1, ans);
        }
        return ans;
    }
};