// Runtime: 3ms
// Memory: 18.6MB
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
        int list_num = 0;
        for(ListNode* list : lists) {
            while(list) {
                pq.push({list->val, list_num});
                list = list->next;
            }
            list_num++;
        }

        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while(!pq.empty()) {
            ptr->next = lists[pq.top().second];
            ptr = ptr->next;
            lists[pq.top().second] = lists[pq.top().second]->next;
            pq.pop();
        }
        return ans->next;
    }
};
