// Runtime: 35ms
// Memory: 35.56MB
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* next = prev->next;
        while(next) {
            prev->next = new ListNode(std::gcd(prev->val, next->val), next);
            prev = next;
            next = prev->next;
        }
        return head;
    }
};
