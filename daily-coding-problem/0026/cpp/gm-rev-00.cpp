#include <iostream>
#include <vector>

class ListNode {
public:
    ListNode* next;
    int val;
    ListNode(int val, ListNode* next = nullptr) {
        this->val = val;
        if(next)
            this->next = next;
    }
    ListNode(std::vector<int> LL) {
        this->val = LL[0];
        ListNode* curr = this;
        for(int i = 1; i < LL.size(); i++) {
            curr->next = new ListNode(LL[i]);
            curr = curr->next;
        }
    }
};

void deleteKthFromEnd(ListNode* head, int k) {
    ListNode* par;
    ListNode* curr = head;
    while(k-- >= 0)
        curr = curr->next;
    par = head;
    while(curr) {
        curr = curr->next;
        par = par->next;
    }

    curr = par->next;
    par->next = curr->next;
    delete curr;
}

int main() {
    ListNode* ll = new ListNode({1,2,3,5,7,11,13,17,19,23});
    int k = 5;

    ListNode* ptr = ll;
    std::cout << "The LL before deletion of the " << k << "th last node:" << std::endl;
    while(ptr) {
        std::cout<< ptr->val <<" ";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
    deleteKthFromEnd(ll, k);
    std::cout << "The LL after deletion:"<<std::endl;
    ptr = ll;
    while(ptr){
        std::cout<< ptr->val <<" ";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
}
