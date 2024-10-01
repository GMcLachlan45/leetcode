#include <iostream>
#include <utility>

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode (T val = T(), TreeNode<T>* l = nullptr, TreeNode<T>* r = nullptr) {
        value = val;
        left = l;
        right = r;
    };
};

std::pair<int,int> helper(TreeNode<int>* root) {
    if(!root)
        return {0,true};

    std::pair<int,int> l = helper(root->left);
    std::pair<int,int> r = helper(root->right);
    bool isUnary = l.second && r.second;
    if(root->left && root->left->value != root->value)
        isUnary = false;
    if(root->right && root->right->value != root->value)
        isUnary = false;
    return {l.first + r.first + (int) isUnary, isUnary};
}

int countUnarySubtrees(TreeNode<int>* root) {
    return helper(root).first;
}
int main() {

    TreeNode<int>* root = new TreeNode<int>(5, new TreeNode<int>(5), new TreeNode<int>(4, new TreeNode<int>(4)));
    std::cout<< "The given tree has " << countUnarySubtrees(root) <<" unary subtrees." << std::endl;

    root = new TreeNode<int>(0, new TreeNode<int>(1), new TreeNode<int>(0, new TreeNode<int>(1,new TreeNode<int>(1),new TreeNode<int>(1)), new TreeNode<int>(0)));
    std::cout<< "The given tree has " << countUnarySubtrees(root) <<" unary subtrees." << std::endl;
    root = new TreeNode<int>(1, new TreeNode<int>(1), new TreeNode<int>(0, new TreeNode<int>(1,new TreeNode<int>(),new TreeNode<int>(1)), new TreeNode<int>(0)));
    std::cout<< "The given tree has " << countUnarySubtrees(root) <<" unary subtrees." << std::endl;
}
