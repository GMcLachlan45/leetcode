// Runtime: 18ms
// Memory: 23.3MB
class MyCircularDeque {
    class ListNode {
    public:
        ListNode* next;
        ListNode* prev;
        int val;

        ListNode(ListNode* node) {
            this->val = -1;
            this->prev = node;
        }
    };

    ListNode* front;
    ListNode* back;

public:
    MyCircularDeque(int k) {
        front = new ListNode(nullptr);
        back = front;
        for(int i = 1; i < k; i++) {
            back->next = new ListNode(back);
            back = back->next;
        }
        front->prev = back;
        back->next = front;
        back = front;
    }

    bool insertFront(int value) {
        if(isFull())
            return false;
        front = front->prev;
        front->val = value;
        return true;
    }

    bool insertLast(int value) {
        if(isFull())
            return false;
        back->val = value;
        back = back->next;
        return true;
    }

    bool deleteFront() {
        if(isEmpty())
            return false;
        front->val = -1;
        front = front->next;
        return true;
    }

    bool deleteLast() {
        if(isEmpty())
            return false;
        back = back->prev;
        back->val = -1;
        return true;
    }

    int getFront() {
        return front->val;
    }

    int getRear() {
        return back->prev->val;
    }

    bool isEmpty() {
        return back == front && front->val == -1;
    }

    bool isFull() {
        return back == front && front->val != -1;
    }
};
