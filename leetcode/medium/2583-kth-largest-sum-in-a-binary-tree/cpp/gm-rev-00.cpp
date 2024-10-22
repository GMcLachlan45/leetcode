// Runtime: 833ms
// Memory: 173.5MB
class Solution {
    std::vector<long long> level_sums;
    void helper(TreeNode* root, int level) {
        if(!root)
            return;
        if(level_sums.size() <= level)
            level_sums.push_back(0);
        level_sums[level] += root->val;
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        helper(root, 0);
        if(level_sums.size() < k)
            return -1;
        std::sort(level_sums.begin(), level_sums.end(), std::greater<>());
        return level_sums[k-1];
    }
};
