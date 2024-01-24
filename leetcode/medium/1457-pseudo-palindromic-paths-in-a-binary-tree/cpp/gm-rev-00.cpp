// Runtime: 267ms
// Memory: 177.67MB
class Solution {
    int helper(TreeNode* root, std::vector<int>* nums) {
        (*nums)[root->val]++;
        if(!root->left && !root->right) {
            bool odd = false;
            for(int i = 1; i <= 9; i++) {
                if(nums->at(i)%2) {
                    if(odd) {
                        (*nums)[root->val]--;
                        return 0;
                    }
                    odd = true;
                }
            }
            (*nums)[root->val]--;
            return 1;
        }
        int ret = 0;
        if(root->left)
            ret += helper(root->left, nums);
        if(root->right)
            ret += helper(root->right, nums);
        (*nums)[root->val]--;
        return ret;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return helper(root, new std::vector<int>(10));
    }
};
