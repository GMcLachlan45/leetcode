// Runtime 19ms
// Memory 28.9MB
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
    bool isCompleteSubtree(TreeNode* root, TreeNode* subRoot){
        if(root && subRoot && root->val == subRoot->val){
            return isCompleteSubtree(root->left, subRoot->left) 
                && isCompleteSubtree(root->right, subRoot->right);
        } else 
            return !subRoot && !root; 
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        else 
            return isCompleteSubtree(root, subRoot) 
                || isSubtree(root->left, subRoot) 
                || isSubtree(root->right, subRoot);
    }
};
