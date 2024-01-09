// Runtime: 4ms
// Memory: 13.35MB
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> treeLeaves;
        std::stack<TreeNode*> st;
        st.push(root1);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(!node)
                continue;
            if(!node->left && !node->right)
                treeLeaves.push_back(node->val);
            else {
                st.push(node->right);
                st.push(node->left);
            }
        }
        for(auto x : treeLeaves)
            std::cout<<x<<" ";

        int ptr = 0;
        st.push(root2);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if(!node)
                continue;
            if(!node->left && !node->right && (ptr >= treeLeaves.size() || node->val != treeLeaves[ptr++]))
                return false;
            else {
                st.push(node->right);
                st.push(node->left);
            }
        }
        return ptr == treeLeaves.size();
    }
};
