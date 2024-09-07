// Runtime: 23ms
// Memory: 30.8MB
class Solution {
    bool helper(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root || head->val != root->val)
            return false;
        return helper(head->next, root->left) || helper(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        return (head->val == root->val && helper(head, root)) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
