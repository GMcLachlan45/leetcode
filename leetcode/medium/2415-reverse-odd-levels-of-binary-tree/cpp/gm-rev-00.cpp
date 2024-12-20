// Runtime: 0ms
// Memory: 79.1MB
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()) {
            TreeNode* l = q.front();
            q.pop();
            TreeNode* r = q.front();
            q.pop();
            if(!l)
                continue;
            int temp = l->val;
            l->val = r->val;
            r->val = temp;
            if(!l->left)
                continue;
            q.push(l->left->left);
            q.push(r->right->right);
            q.push(l->left->right);
            q.push(r->right->left);

            q.push(l->right->left);
            q.push(r->left->right);
            q.push(l->right->right);
            q.push(r->left->left);
        }
        return root;
    }
};
