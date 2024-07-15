// Runtime: 788ms
// Memory: 290.3MB
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, TreeNode*> cache;
        std::unordered_set<int> rootFinder;

        for(std::vector<int> node : descriptions) {
            cache[node[1]] = new TreeNode(node[1]);
            if(!cache[node[0]] && !rootFinder.count(node[0]))
                rootFinder.insert(node[0]);
            rootFinder.erase(node[1]);
        }

        cache[(*rootFinder.begin())] = new TreeNode((*rootFinder.begin()));

        for(std::vector<int> node : descriptions) {
            if(node[2])
                cache[node[0]]->left = cache[node[1]];
            else
                cache[node[0]]->right = cache[node[1]];
        }
        return cache[(*rootFinder.begin())];
    }
};
