// Runtime: 19ms
// Memory: 27.1MB
class Solution {
    // Returns true if the given root should be deleted
    bool helper(TreeNode* root, std::vector<int>* to_delete, std::vector<TreeNode*>* forest) {
        if(!root)
            return false;
        if(helper(root->left, to_delete, forest))
            root->left = nullptr;
        if(helper(root->right, to_delete, forest))
            root->right = nullptr;

        // if this node is to be deleted
        if(std::binary_search(to_delete->begin(), to_delete->end(), root->val)) {
            // push its existing children to the forest
            if(root->left)
                forest->push_back(root->left);
            if(root->right)
                forest->push_back(root->right);
            return true;
        }
        return false;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        std::sort(to_delete.begin(), to_delete.end());
        std::vector<TreeNode*> forest;
        if(!helper(root, &to_delete, &forest))
            forest.push_back(root);
        return forest;
    }
};
