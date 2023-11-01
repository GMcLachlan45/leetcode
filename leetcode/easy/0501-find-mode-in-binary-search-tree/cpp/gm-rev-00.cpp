// Runtime: 17ms
// Memory: 25.7MB
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        std::unordered_map<int, int> mp;
        std::stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* n = st.top();
            st.pop();
            if(n->left)
                st.push(n->left);
            if(n->right)
                st.push(n->right);
            mp[n->val]++;
        }
        int maxVal = 0;
        std::vector<int> maxNums;
        for(std::pair<int,int> x: mp) {
            if(x.second > maxVal) {
                maxNums.clear();
                maxVal = x.second;
            }
            if(x.second == maxVal) {
                maxNums.push_back(x.first);
            }
        }
        return maxNums;
    }
};
