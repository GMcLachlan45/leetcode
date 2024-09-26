#include <iostream>
#include <algorithm>
#include <string>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, TreeNode* l, TreeNode* r) {
        this->val = val;
        this->left = l;
        this->right = r;
    };
    TreeNode(int val) {
        this->val = val;
    };
    TreeNode() {};
};


std::string serialize(TreeNode* root) {
    if(!root)
        return "{}";

    return (std::string) "{"
        + "\"v\":" + std::to_string(root->val)
        + ",\"l\":" + serialize(root->left)
        + ",\"r\":" + serialize(root->right)
        + "}";
};

TreeNode* deserialize(std::string s) {
    if(s == "{}")
        return nullptr;
    int start = 5;
    int end = start;
    while(s[end] != ',')
        end++;

    int val = std::stoi(s.substr(start, end-start));

    int bracketCount = 1;
    start = end + 5;
    end = start + 1;
    while(bracketCount) {
        if(s[end] =='{')
            bracketCount++;
        else if(s[end] == '}')
            bracketCount--;
        end++;
    }
    TreeNode* l = deserialize(s.substr(start, end-start));

    bracketCount = 1;
    start = end + 5;
    end = start + 1;
    while(bracketCount){
        if(s[end] =='{')
            bracketCount++;
        else if(s[end] == '}')
            bracketCount--;
        end++;
    }
    TreeNode* r = deserialize(s.substr(start, end-start));

    return new TreeNode(val, l, r);
};

bool assertIsDeepCopy(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2)
        return true;
    else if(t1 && t2) {
        return t1->val == t2->val
            && assertIsDeepCopy(t1->left, t2->left)
            && assertIsDeepCopy(t1->right, t2->right);
    } else
        return false;
};

#include <queue>
void printLevelOrderTraversal(TreeNode* root){
    std::queue<TreeNode*> q;
    q.push(root);

    std::cout<<"[";
    while(!q.empty()) {
        if(q.front()){
            std::cout<<q.front()->val<<",";
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
    }
    std::cout<<"]"<<std::endl;
}

int main() {
    TreeNode* origTree = new TreeNode(5, new TreeNode(2, nullptr, new TreeNode(10)), new TreeNode(4, new TreeNode(5), nullptr));
    std::cout<< "The original Tree:"<<std::endl;
    printLevelOrderTraversal(origTree);

    std::string ser = serialize(origTree);
    std::cout<<"Produces the string:"<<std::endl;
    std::cout<<ser<<std::endl;

    TreeNode* dsTree = deserialize(ser);
    std::cout<<"Which when deserialized produces:"<<std::endl;
    printLevelOrderTraversal(dsTree);

    if(assertIsDeepCopy(origTree, dsTree))
        std::cout << "The serialization and deserialization was sucessful." <<std::endl;
    else
        std::cout << "The Serialization and deserialization was NOT successful." <<std::endl;
}
