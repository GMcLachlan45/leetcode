// Runtime 14ms
// Memory 22.33MB
class Solution {
    void helper(TreeNode* root, int depth, vector<int>* arr) {
        if(!root)
            return;
        if(depth >= arr->size())
            arr->push_back(root->val);
        else if(root->val > (*arr)[depth])
            (*arr)[depth] = root->val;
        helper(root->left, depth+1, arr);
        helper(root->right, depth+1, arr);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> arr;
        helper(root, 0, &arr);
        return arr;
    }
};
