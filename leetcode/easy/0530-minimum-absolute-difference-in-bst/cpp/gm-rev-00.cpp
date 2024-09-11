// Runtime: 17ms
// Memory: 24.5MB
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        int ans = 100000;
        while(!q.empty()) {
            TreeNode* ptr = q.front()->left;
            if(ptr) {
                q.push(ptr);
                while(ptr->right)
                    ptr = ptr->right;
                if(q.front()->val - ptr->val < ans)
                    ans = q.front()->val - ptr->val;
            }

            ptr = q.front()->right;
            if(ptr) {
                q.push(ptr);
                while(ptr->left)
                    ptr = ptr->left;
                if(ptr->val - q.front()->val < ans)
                    ans = ptr->val - q.front()->val;
            }
            q.pop();
        }

        return ans;
    }
};
