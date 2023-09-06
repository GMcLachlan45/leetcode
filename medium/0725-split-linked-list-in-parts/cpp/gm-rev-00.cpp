// Runtime 4ms
// Memory 8.92MB
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* ptr = head;
        int count = 0;
        while(ptr){
            count++;
            ptr = ptr->next;
        }
        vector<ListNode*> ret;
        if(count < k) {
            while(k) {
                if(head){
                    ptr = head;
                    ListNode* temp = head->next;
                    head->next = nullptr;
                    ret.push_back(head);
                    head = temp;
                } else
                    ret.push_back(nullptr);
                    k--;
            }
            return ret;
        }
        int extras = count % k;
        ptr = head;
        for(int i = 0; i < k-1; i++) {
            std::cout << std::endl << i<<": ";
            for (int j = 0; j+1 < count/k; j++) {
                ptr = ptr->next;
            }
            if(extras&&ptr) {
                ptr = ptr->next;
                extras--;
            }
            if(ptr){
                ListNode* temp = ptr->next;
                ptr->next = NULL;
                ret.push_back(head);
                head = temp;
                ptr = head;
            }
            else
                ret.push_back(nullptr);
        }
        ret.push_back(head);

        return ret;
    }
};
