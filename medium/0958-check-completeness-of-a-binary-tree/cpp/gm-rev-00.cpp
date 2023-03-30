// Runtime 7ms
// Memory 10.4MB
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // tuple of <isComplete, leftDepth, rightDepth>
    std::tuple<bool, int, int> isCompleteAndBalanced(TreeNode* root) {
        if(!root)
            return {true,0,0};

        std::tuple<bool,int,int> l = isCompleteAndBalanced(root->left);
        // early return if not balanced, or right > left or left-1 > right
        if(!std::get<0>(l) || std::get<1>(l) < std::get<2>(l) || std::get<1>(l) - 1 > std::get<2>(l) )
            return {false, 0, 0};

        std::tuple<bool,int,int> r = isCompleteAndBalanced(root->right);
        // early return if not balanced, or right > left or left-1 > right
        if(!std::get<0>(r) || std::get<1>(r) < std::get<2>(r) || std::get<1>(r) - 1 > std::get<2>(r) )
            return {false, 0, 0};

        // otherwise we return the row check with the new left and right heights
        return {
            std::get<1>(l) - std::get<2>(r) < 2
            && ((std::get<1>(l) > std::get<2>(l) && std::get<2>(l) == std::get<1>(r) && std::get<1>(r) == std::get<2>(r))
            || (std::get<1>(l) == std::get<2>(l) && std::get<2>(l) > std::get<1>(r) && std::get<1>(r) == std::get<2>(r))
            || (std::get<1>(l) == std::get<2>(l) && std::get<2>(l) == std::get<1>(r) && std::get<1>(r) >= std::get<2>(r))),
            std::get<1>(l) + 1, 
            std::get<2>(r) + 1
        };
    }

public:
    bool isCompleteTree(TreeNode* root) {
        return std::get<0>(isCompleteAndBalanced(root));
    }
};
