// Runtime: 15ms
// Memory: 23.6MB
class Solution {
    // First number is the number of nodes that satisfy what we want
    // Second is the total number of nodes in this subtree
    // Third is the sum of the subtree
    std::vector<int> averageOfSubtreeAndTotalNodes(TreeNode* root) {
        if(!root)
            return {0,0,0};
        std::vector<int> l =  averageOfSubtreeAndTotalNodes(root->left);
        std::vector<int> r =  averageOfSubtreeAndTotalNodes(root->right);
        if((l[2] + r[2] + root->val)/(l[1] + r[1] +1) == root->val)
            return {l[0]+r[0]+1, l[1]+r[1]+1,l[2] + r[2] + root->val};
        return {l[0]+r[0], l[1]+r[1]+1,l[2] + r[2] + root->val};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        return averageOfSubtreeAndTotalNodes(root)[0];
    }
};
