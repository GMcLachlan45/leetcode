// Runtime: 115ms
// Memory: 64.9MB
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        else if(low > root->val)
            return rangeSumBST(root->right, low, high);
        else if(high < root->val)
            return rangeSumBST(root->left, low, high);
        else
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
