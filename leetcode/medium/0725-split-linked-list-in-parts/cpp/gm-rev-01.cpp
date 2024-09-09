// Runtime: 5ms
// Memory: 14MB
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int numOfNodes = 0;
        ListNode* ptr = head;
        while(ptr){
            numOfNodes++;
            ptr = ptr->next;
        }

        std::vector<ListNode*> ret(k);
        head = new ListNode(0, head);
        while(k) {
            if(!head)
                break;

            ret[ret.size()-k] = head->next;
            head->next = nullptr;
            head = ret[ret.size()-k];

            for(int i = std::ceil((double) numOfNodes/k); head && i > 1; i--)
                head = head->next;
            numOfNodes -= std::ceil((double) numOfNodes/k--);
        }
        return ret;
    }
};
