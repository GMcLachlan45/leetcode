// Runtime: 6ms
// Memory: 12.31MB
class Solution {
    // First number is the number of nodes that satisfy what we want
    // Second is the total number of nodes in this subtree
    // Third is the sum of the subtree
    std::array<int, 3> averageOfSubtreeAndTotalNodes(TreeNode* root) {
        if(!root)
            return {0,0,0};
        std::array<int, 3> l =  averageOfSubtreeAndTotalNodes(root->left);
        std::array<int, 3> r =  averageOfSubtreeAndTotalNodes(root->right);

        return {l[0] + r[0] + (int)((l[2] + r[2] + root->val)/(l[1] + r[1] +1) == root->val),
             l[1] + r[1] + 1,
             l[2] + r[2] + root->val};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        return averageOfSubtreeAndTotalNodes(root)[0];
    }
};
