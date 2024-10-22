// Runtime: 40ms
// Memory: 171.1MB
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::queue<std::pair<TreeNode*, int>> q;
        std::priority_queue<long long> level_sum;
        int level = 0;
        long long sum = 0;
        q.push({root, 0});

        while(!q.empty()) {
            if(q.front().second != level) {
                level_sum.push(sum);
                level++;
                sum = 0;
            }
            if(q.front().first) {
                sum += q.front().first->val;
                q.push({q.front().first->left, q.front().second + 1});
                q.push({q.front().first->right, q.front().second + 1});
            }
            q.pop();
        }
        while(!level_sum.empty() && --k)
            level_sum.pop();
        return (level_sum.empty()) ? -1 : level_sum.top();

    }
};
