// Runtime: 131ms
// Memory: 92.02MB

class Solution {
    bool findStart(TreeNode* root, int start) {
        if(!root)
            return false;
        if(root->val == start) {
            root->val = 0;
            return true;
        }
        if(findStart(root->left, start)) {
            root->val = root->left->val - 1;
            return true;
        }
        if(findStart(root->right, start)) {
            root->val = root->right->val - 1;
            return true;
        }
        return false;
    }

    void paintNegative(TreeNode* root) {
        if(!root)
            return;
        root->val *= -1;
        paintNegative(root->left);
        paintNegative(root->right);
    }
    void paint(TreeNode* root) {
        if(!root)
            return;
        if(root->left && root->left->val < 0) {
            root->left->val = root->val + 1;
        }
        paint(root->left);
        if(root->right && root->right->val < 0) {
            root->right->val = root->val + 1;
        }
        paint(root->right);
    }

    int findMax(TreeNode* root) {
        if(!root)
            return -1;
        return std::max(root->val,std::max(findMax(root->left), findMax(root->right)));
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        findStart(root, start);
        paintNegative(root);
        paint(root);
        return findMax(root);
    }
};
