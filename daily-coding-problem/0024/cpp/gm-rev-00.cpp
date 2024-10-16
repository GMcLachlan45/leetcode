#include <iostream>
#include <stdexcept>
template <typename T>
class LockingTreeNode {
private:
    T val;
    bool locked;
    LockingTreeNode* parent;
    LockingTreeNode* left;
    LockingTreeNode* right;

    bool setParent(LockingTreeNode* parent) {
        this->parent = parent;
        return true;
    }

public:
    // Locking functions
    bool isLocked() {
        return this->locked;
    }

    bool lock() {
        if((left == nullptr || left->isLocked()) && (right == nullptr || right->isLocked())) {
            this->locked = true;
            return true;
        } else
            return false;
    }

    bool unlock() {
        if(parent == nullptr || !parent->isLocked()) {
            this->locked = false;
            return true;
        } else
            return false;
    }

    // Basic Binary Tree OO functions
    LockingTreeNode* getLeft() {
        return this->left;
    }
    LockingTreeNode* getRight() {
        return this->right;
    }
    LockingTreeNode* getParent() {
        return this->parent;
    }
    T getVal() {
        return this->val;
    }

    bool setLeft(LockingTreeNode* left) {
        if(isLocked())
            return false;
        this->left = left;
        return true;
    }
    bool setRight(LockingTreeNode* right) {
        if(isLocked())
            return false;
        this->right = right;
        return true;
    }
    bool setVal(T val) {
        if(isLocked())
            return false;
        this->val = val;
        return true;
    }

    LockingTreeNode(T val, LockingTreeNode* left = nullptr, LockingTreeNode* right = nullptr) {
        this->val = val;
        this->locked = false;
        if(left)
            left->setParent(this);
        setLeft(left);
        if(right)
            right->setParent(this);
        setRight(right);
    }
};

int main() {
    LockingTreeNode<int>* lbt = new LockingTreeNode<int>(5, new LockingTreeNode<int>(1), new LockingTreeNode<int>(4));
    std::cout << lbt->lock()<<std::endl
              << lbt->getLeft()->lock()<<std::endl
              << lbt->getRight()->lock()<<std::endl

              << lbt->lock()<<std::endl
              << lbt->setVal(55)<<std::endl;
}
