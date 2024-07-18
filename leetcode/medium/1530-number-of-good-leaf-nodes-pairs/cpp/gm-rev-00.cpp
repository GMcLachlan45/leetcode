// Runtime: 40ms
// Memory: 33MB
class Solution {
    std::vector<int> helper(TreeNode* root, int distance) {
        std::vector<int> ret(distance);
        if(!root)
            return ret;
        else if (!root->left && !root->right) {
            ret[1]++;
            return ret;
        }

        std::vector<int> l_distances = helper(root->left, distance);
        std::vector<int> r_distances = helper(root->right, distance);

        ret[0] += l_distances[0] + r_distances[0];

        for(int i = 1; i < distance; i++)
            for(int j = 1; i + j <= distance; j++)
                ret[0] += l_distances[i] * r_distances[j];

        for(int i = 2; i < distance; i++)
            ret[i] = l_distances[i-1] + r_distances[i-1];

        return ret;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        if(distance == 1)
            return 0;
        return helper(root, distance)[0];
    }
};
