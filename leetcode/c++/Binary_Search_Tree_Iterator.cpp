/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> st;
    TreeNode *p = nullptr;
public:
    BSTIterator(TreeNode *root) {
        p = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while(p || !st.empty()){
            if(p){
                st.push(p);
                p = p->left;
            }else{
                return true;
            }
        }
        
        return false;
    }

    /** @return the next smallest number */
    int next() {
        int val;

        p = st.top();
        st.pop();
        val = p->val;
        p = p->right;
        
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
