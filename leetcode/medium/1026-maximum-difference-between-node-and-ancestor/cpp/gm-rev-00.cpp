// Runtime: 22ms
// Memory: 11.46MB
class Solution {

    int helper(TreeNode* root, std::vector<int>* ancestors) {
        if(!root)
            return 0;
        int max = 0;
        for(int ancest : *ancestors)
            max = std::max(max, std::abs(root->val - ancest));

        ancestors->push_back(root->val);
        max = std::max(max, helper(root->left, ancestors));
        max = std::max(max, helper(root->right, ancestors));
        ancestors->pop_back();
        return max;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        std::vector<int> adam;
        adam.push_back(root->val);
        return std::max(helper(root->left, &adam), helper(root->right, &adam));
    }
};
