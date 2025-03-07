/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        cin.tie(0) -> sync_with_stdio(false);
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == NULL){
                if(!q.empty() and q.front() != NULL) {q.push(NULL);}
                continue;
            }
            q.push(curr -> left);
            q.push(curr -> right);
            curr -> next = q.front();
        }
        return root;
    }
};