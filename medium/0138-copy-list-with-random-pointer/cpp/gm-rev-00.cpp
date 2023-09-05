// Runtime 12ms
// Memory 11.40MB
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        std::unordered_map<Node*, Node*> s;
        Node* cHead = new Node(head->val);

        s[head] = cHead;

        Node* ptr = head;
        Node* cPtr = cHead;
        while(ptr->next) {
            ptr = ptr->next;
            cPtr->next = new Node(ptr->val);
            cPtr = cPtr->next;
            s[ptr] = cPtr;
        }

        ptr = head;
        cPtr = cHead;

        cPtr->random = s[ptr->random];
        while(ptr->next) {
            ptr = ptr->next;
            cPtr = cPtr->next;
            cPtr->random = s[ptr->random];
        }
        return cHead;
    }
};
