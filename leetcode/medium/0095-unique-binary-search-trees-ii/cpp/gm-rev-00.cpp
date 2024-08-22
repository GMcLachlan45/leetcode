// Runtime: 11ms
// Memory: 17.9MB
class Solution {
    // Cache for the trees from l to r
    std::vector<TreeNode*> cache[9][9];

    std::vector<TreeNode*> helper(int l, int r) {
        if(r<l)
            return {nullptr};
        if(cache[l][r].size())
            return cache[l][r];

        for(int i = l; i <= r; i++)
            for(auto leftTree : helper(l, i-1))
                for(auto rightTree : helper(i+1, r))
                    cache[l][r].push_back(new TreeNode(i, leftTree, rightTree));
        return cache[l][r];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
