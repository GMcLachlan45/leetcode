#include <iostream>
#include <cstdint>

class XorLinkedList {
private:
    class ListNode {
    public:
        int val;
        std::uintptr_t both;
        ListNode(int val) {
            this->val = val;
        };
        ListNode(){
            this->val = 0;
        };

    };

public:
    ListNode* head;
    ListNode* tail;
    void add(int elem) {
        if(!head) {
            head = new ListNode(elem);
            tail = head;
            return;
        }
        ListNode* added = new ListNode(elem);
        added->both = reinterpret_cast<std::uintptr_t>(tail);
        tail->both ^= reinterpret_cast<std::uintptr_t>(added);
        tail = added;
    };

    int get(int idx) {
        if(!head){
            return -1;
        }
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while(idx && ptr) {
            ListNode* next = (ListNode*) (ptr->both ^ reinterpret_cast<std::uintptr_t>(prev));
            prev = ptr;
            ptr = next;
            idx--;
        }
        return (ptr) ? ptr->val : -1;
    }

    void printContents() {
        if(!head){
            std::cout<<"The LL is empty!"<<std::endl;
            return;
        }
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while(ptr) {
            std::cout<<ptr->val;
            ListNode* next = (ListNode*) (ptr->both ^ reinterpret_cast<std::uintptr_t>(prev));
            prev = ptr;
            ptr = next;
            if(ptr)
                std::cout<<"<->";
        }
        std::cout<<std::endl;
    }
    XorLinkedList() { };
};

int main() {
    XorLinkedList ll;
    ll.printContents();
    ll.add(1);
    ll.add(24);
    ll.add(203);
    ll.printContents();
    std::cout<<"Trying to get LL[3] yields: "<<ll.get(3)<<std::endl;
    std::cout<<"Trying to get LL[2] yields: "<<ll.get(2)<<std::endl;
}
