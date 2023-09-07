//Runtime 0ms
//Memory 7.52MB
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;

        int count = 1;
        ListNode* ptr = head;
        while(count < left - 1){
            ptr = ptr->next;
            count++;
        }
        ListNode* unchangedFront = ptr;
        if(left != 1){
            ptr = ptr->next;
            count++;
        }

        std::stack<ListNode*> s;
        while(count <= right) {
            s.push(ptr);
            ptr = ptr->next;
            count++;
        }
        ListNode* revHead = s.top();
        ListNode* revPtr = revHead;
        s.pop();
        while (!s.empty()) {
            std::cout << revPtr << std::endl;
            revPtr->next = s.top();
            revPtr = s.top();
            s.pop();
        }

        // Connect the reversed list to the unchanged parts
        if(left !=1)
            unchangedFront->next = revHead;
        else
            head = revHead;
        revPtr->next=ptr;
        return head;
    }
};
