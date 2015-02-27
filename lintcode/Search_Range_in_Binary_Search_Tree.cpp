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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        if(!root) return {};
        
        vector<int> result;
        searchRangeHelper(result, root, k1, k2);
        sort(result.begin(), result.end());
        
        return result;
    }
private:
    void searchRangeHelper(vector<int> &result, TreeNode *root, int k1, int k2){
        if(!root) return;
        
        if(root->val < k1) searchRangeHelper(result, root->right, k1, k2);
        else if(root->val > k2) searchRangeHelper(result, root->left, k1, k2);
        else {
            result.push_back(root->val);
            searchRangeHelper(result, root->left, k1, k2);
            searchRangeHelper(result, root->right, k1, k2);
        }
    }
};
