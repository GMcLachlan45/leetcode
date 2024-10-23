// Runtime: 38ms
// Memory: 324.4MB
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        std::queue<int> toSubtract;
        toSubtract.push(root->val);

        int row = 0;
        int current_row_sum = root->val;
        int next_row_sum = 0;

        while(!q.empty()) {
            if(q.front().second > row) {
                current_row_sum = next_row_sum;
                next_row_sum = 0;
                row++;
            }

            q.front().first->val = current_row_sum - toSubtract.front();

            if(q.front().first->left && q.front().first->right) {
                q.push({q.front().first->left, q.front().second + 1});
                q.push({q.front().first->right, q.front().second + 1});

                next_row_sum += q.front().first->left->val + q.front().first->right->val;
                toSubtract.push(q.front().first->left->val + q.front().first->right->val);
                toSubtract.push(q.front().first->left->val + q.front().first->right->val);

            } else if(q.front().first->left) {
                q.push({q.front().first->left, q.front().second + 1});

                next_row_sum += q.front().first->left->val;
                toSubtract.push(q.front().first->left->val);
            } else if(q.front().first->right) {
                q.push({q.front().first->right, q.front().second + 1});

                next_row_sum += q.front().first->right->val;
                toSubtract.push(q.front().first->right->val);
            }

            q.pop();
            toSubtract.pop();
        }

        return root;
    }
};
