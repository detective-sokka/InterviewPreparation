// https://leetcode.com/problems/balanced-binary-tree/description/
#include <algorithm>
using namespace std;

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
    int checkBalanceWithDepth(TreeNode* root, bool& result) {
        if (!root)
            return 0;

        int leftDepth = checkBalanceWithDepth(root->left, result);
        int rightDepth = checkBalanceWithDepth(root->right, result);

        if (abs(leftDepth - rightDepth) > 1)
            result = false;
        
        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {       
        bool result = true;
        checkBalanceWithDepth(root, result);
        return result;
    }
};