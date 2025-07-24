// https://leetcode.com/problems/subtree-of-another-tree/
/**
 * Definition for a binary tree node.
**/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool verifyTrees(TreeNode *root, TreeNode* subRoot) {
        
        if (!root && !subRoot)
            return true;

        if (!root || ! subRoot)      
            return false;        
        
        if (root->val != subRoot->val)
            return false;

        return verifyTrees(root->left, subRoot->left) && verifyTrees(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        if (!root || ! subRoot)      
            return false;      
        
        if (root->val == subRoot->val && verifyTrees(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot)  || isSubtree(root->right, subRoot);
    }
};