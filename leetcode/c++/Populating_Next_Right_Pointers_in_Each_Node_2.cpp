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
        if(!root) return;
        if(!root->left && !root->right) return;
        
        queue<TreeLinkNode *> p, q;
        p.push(root);
        
        while(!p.empty()){
            TreeLinkNode *t = p.front();
            p.pop();
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            
            if(!p.empty()) t->next = p.front();
            else swap(p, q);
        }
        
    }
};
