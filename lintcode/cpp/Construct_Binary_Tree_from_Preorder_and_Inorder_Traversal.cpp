/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    TreeNode *buildTreeHelper(vector<int>::iterator ps, vector<int>::iterator pe,
        vector<int>::iterator is, vector<int>::iterator ie){
        if(ps == pe) return nullptr;
        if(ps+1 == pe) return new TreeNode(*ps);
        
        int x = *ps;
        vector<int>::iterator it = find(is, ie, x);
        
        TreeNode *root = new TreeNode(x);
        root->left = buildTreeHelper(ps+1, ps+(it-is)+1, is, it);
        root->right = buildTreeHelper(ps+(it-is+1), pe, it+1, ie);
        return root;    
    }
};
