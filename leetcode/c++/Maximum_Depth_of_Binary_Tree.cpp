/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
    
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
            
        return max(lDepth, rDepth)+1; 
    }
};

int main(){

    Solution sol;

    {
        TreeNode *root = new TreeNode(0);
        root->left = new TreeNode(1); 
        cout << sol.maxDepth(root) << endl;

        delete root->left;
        delete root;
    }
}

