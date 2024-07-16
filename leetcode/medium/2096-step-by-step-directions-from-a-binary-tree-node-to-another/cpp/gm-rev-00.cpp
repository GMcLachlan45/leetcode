// Runtime: 1363ms
// Memory: 145.2MB
class Solution {
    std::string helper(TreeNode* root, int s, std::vector<char>* path) {
        if(!root)
            return "";
        if(root->val == s)
            return std::string(path->begin(), path->end());
        path->push_back('L');
        std::string l = helper(root->left, s, path);
        path->pop_back();
        if(l.empty()){
            path->push_back('R');
            l = helper(root->right, s, path);
            path->pop_back();
        }
        return l;

    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        std::string startPath = helper(root, startValue, new std::vector<char>);
        std::string endPath = helper(root, destValue, new std::vector<char>);

        int shared = 0;
        while(shared < std::min(startPath.size(), endPath.size()) && startPath[shared] == endPath[shared])
            shared++;

        return std::string(startPath.size()-shared, 85)
            + endPath.substr(shared, endPath.size()-shared);
    }
};
