// Runtime: 4ms
// Memoyry: 8.64MB
class Solution {
    void helper(TreeNode* root, std::vector<int>* ret) {
        if(root) {
            helper(root->left, ret);
            ret->push_back(root->val);
            helper(root->right, ret);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret = {};
        helper(root, &ret);
        return ret;
    }
};
