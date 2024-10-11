#include <iostream>
#include <vector>

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val, ListNode* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};


int findIntersect(ListNode* l1, ListNode* l2) {
    ListNode* ptr = l1;

    // get the total size of the LLs
    int l1_size = 0;
    int l2_size = 0;
    while(ptr) {
        l1_size++;
        ptr = ptr->next;
    }
    ptr = l2;
    while(ptr) {
        l2_size++;
        ptr = ptr->next;
    }

    // trim one of the LLs so that they're the same size
    while(l1_size > l2_size) {
        l1 = l1->next;
        l1_size--;
    }
    while(l2_size > l1_size) {
        l2 = l2->next;
        l2_size--;
    }

    // follow each node until we find the intersect
    while(l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;
    }

    return l1->val;
}


int main() {

    ListNode* intersect = new ListNode(3, new ListNode(4));
    ListNode* l1 = new ListNode(1, new ListNode(2, intersect));
    ListNode* l2 = new ListNode(5, new ListNode(6, intersect));
    std::cout<< "The intersect of the lists"<<std::endl;
    ListNode* ptr = l1;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
    ptr = l2;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl<<"Is " << findIntersect(l1, l2)<<std::endl<<std::endl;

    intersect = new ListNode(8, new ListNode(26, new ListNode(99, new ListNode(6))));
    l1 = new ListNode(1, new ListNode(29, intersect));
    l2 = new ListNode(5, new ListNode(200, new ListNode(77, intersect)));
    std::cout<< "The intersect of the lists"<<std::endl;
    ptr = l1;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
    ptr = l2;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl<<"Is " << findIntersect(l1, l2)<<std::endl<<std::endl;

    intersect = new ListNode(1);
    l1 = intersect;
    l2 = intersect;
    std::cout<< "The intersect of the lists"<<std::endl;
    ptr = l1;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
    ptr = l2;
    while(ptr){
        std::cout<< ptr->val<<"->";
        ptr = ptr->next;
    }
    std::cout<<std::endl<<"Is " << findIntersect(l1, l2)<<std::endl;
}
