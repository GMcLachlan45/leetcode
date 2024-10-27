#include <iostream>
#include <vector>

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->left = left;
        this->right = right;
        this->val = val;
    }
};

TreeNode* createBST(std::vector<int> vals) {
    TreeNode* bst = new TreeNode(vals[0]);
    for(int i = 1; i < vals.size(); i++) {
        TreeNode* root = bst;
        while(true) {
            if(vals[i] > root->val) {
                if(!root->right) {
                    root->right = new TreeNode(vals[i]);
                    break;
                } else
                    root = root->right;
            } else {
                if(!root->left) {
                    root->left = new TreeNode(vals[i]);
                    break;
                } else
                    root = root->left;
            }
        }
    }
    return bst;
}

int secondLargest(TreeNode* root) {
    if(root->right) {
        TreeNode* largest = root->right;
        while(largest->right) {
            root = largest;
            largest = largest->right;
        }
        if(!largest->left)
            return root->val;
        root = largest->left;
    } else
        root = root->left;

    while(root->right)
        root = root->right;
    return root->val;
}

int main() {
    TreeNode* input = createBST({1,2,3,4,5});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({5,4,6,7});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({5,4,3,2,1});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({5,1,3,2,4});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({5,1,2,3,4});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({5,1});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;

    input = createBST({1,5});
    std::cout << "The second largest node in the given BST is " << secondLargest(input) <<std::endl;


}
