// Runtime: 426ms
// Memory: 256.52MB
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head->next;
        ListNode* zeroPtr = head;

        while(ptr->next){
            if(ptr->val == 0) {
                zeroPtr->next = ptr;
                zeroPtr = zeroPtr->next;
            } else
                zeroPtr->val += ptr->val;
            ptr = ptr->next;
        }
        zeroPtr->next = nullptr;
        return head;
    }
};
