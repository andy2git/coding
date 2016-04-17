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
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(!root) return true;
        
        //NOTE: needed for INT_MAX element
        if(!root->left && !root->right) return true;
        
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
    
private:
    bool isValidBSTHelper(TreeNode *root, int l, int h){
        if(!root) return true;
        if(root->val <= l || root->val >= h) return false;
        
        return isValidBSTHelper(root->left, l, root->val)
                &&isValidBSTHelper(root->right, root->val, h);
    }
};



/**
 * Solution#1: bottom-up solution
 *  - invalid solution will return {-1, -1} - could a valid range
 *    use pair<int, int> *t = nullptr for invalid case
 */
#include <utility>
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(!root) return true;
        
        pair<int, int> *t = isValidBSTHelper(root);
        
        if(!t) return false;
        else return true;
    }
    
private:
    pair<int, int> *isValidBSTHelper(TreeNode *root){
        if(!root->left && !root->right) return new pair<int, int>(root->val, root->val);
        
        int min = root->val;
        int max = root->val;
        if(root->left){
            pair<int, int> *l = isValidBSTHelper(root->left);
            
            if(!l || l->second >= root->val) return nullptr;
            min = l->first;
        }
        
        if(root->right){
            pair<int, int> *r = isValidBSTHelper(root->right);
            if(!r || r->first <= root->val) return nullptr;
            max = r->second;
        }
        
        return new pair<int, int>(min, max);
    }
};
