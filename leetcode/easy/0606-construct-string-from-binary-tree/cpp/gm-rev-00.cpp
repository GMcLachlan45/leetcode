// Runtime: 18ms
// Memory: 27.4MB
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root->right) {
            if(!root->left)
                return std::to_string(root->val);
            else
                return std::to_string(root->val)+"(" + tree2str(root->left) + ")";
        } else {
            if(!root->left)
                return std::to_string(root->val)+"()("  + tree2str(root->right) +")";
            else
                return std::to_string(root->val) + "(" + tree2str(root->left) + ")("  + tree2str(root->right) + ")";
        }
    }
};
