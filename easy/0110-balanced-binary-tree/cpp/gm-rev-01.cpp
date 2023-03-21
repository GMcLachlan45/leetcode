// Runtime 8ms
// Memory 20.9MB
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int getHeight(TreeNode* root){
        if(root)
            return std::max(getHeight(root->left),getHeight(root->right)) + 1;
        else
            return 0;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root){
            return std::abs(getHeight(root->left) - getHeight(root->right)) < 2
                && isBalanced(root->left) && isBalanced(root->right);
        } else
            return true;
    }
};