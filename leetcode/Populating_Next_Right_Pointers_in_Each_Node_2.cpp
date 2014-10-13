/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        queue<TreeLinkNode *> cq, nq;
        cq.push(root);
        
        TreeLinkNode *t = nullptr;
        while(!cq.empty()){
            t = cq.front();
            cq.pop();
            
            if(t->left) nq.push(t->left);
            if(t->right) nq.push(t->right);
            
            if(!cq.empty()) t->next = cq.front();
            else{
                swap(cq, nq);
            }
        }
    }
};
