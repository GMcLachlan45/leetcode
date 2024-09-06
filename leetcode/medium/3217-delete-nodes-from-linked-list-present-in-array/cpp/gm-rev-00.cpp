// Runtime: 388ms
// Memory: 222.59MB
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::sort(nums.begin(), nums.end());
        auto iter = std::lower_bound(nums.begin(), nums.end(), head->val);
        while(head && iter != nums.end() && *iter == head->val) {
            head = head->next;
            iter = std::lower_bound(nums.begin(), nums.end(), head->val);
        }
        if(!head)
            return head;

        ListNode* ptr = head;
        while(ptr->next) {
            iter = std::lower_bound(nums.begin(), nums.end(), ptr->next->val);
            if(iter != nums.end() && *iter == ptr->next->val)
                ptr->next = ptr->next->next;
            else
                ptr = ptr->next;
        }
        return head;
    }
};
