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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode *buildTreeHelper(vector<int>::iterator is, vector<int>::iterator ie,
    vector<int>::iterator ps, vector<int>::iterator pe){
        if(is == ie) return nullptr;
        if(is+1 == ie) return new TreeNode(*is);
        
        int x = *(pe-1);
        vector<int>::iterator it = find(is, ie, x);
        int m = it - is;
        
        TreeNode *root = new TreeNode(x);
        root->left = buildTreeHelper(is, it, ps, ps+m);
        root->right = buildTreeHelper(it+1, ie, ps+m, pe-1);
        return root;
    }
};
