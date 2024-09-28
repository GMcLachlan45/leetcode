// Runtime: 14ms
// Memory: 22.6MB
class MyCircularDeque {
    std::vector<int> q;
    int front;
    int back;
    int k;
public:
    MyCircularDeque(int k) {
        q = std::vector(k, -1);
        front = 0;
        back = 0;
        this->k = k;
    }

    bool insertFront(int value) {
        if(isFull())
            return false;

        front = (front + k -1)%k;
        q[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if(isFull())
            return false;
        q[back] = value;
        back = (back+1)% k;
        return true;
    }

    bool deleteFront() {
        if(isEmpty())
            return false;
        q[front] = -1;
        front = (front + 1)%k;
        return true;
    }

    bool deleteLast() {
        if(isEmpty())
            return false;
        back = (back + k -1)%k;
        q[back] = -1;
        return true;
    }

    int getFront() {
        return q[front];
    }

    int getRear() {
        return q[(back + k -1)%k];
    }

    bool isEmpty() {
        return back == front && q[front] == -1;
    }

    bool isFull() {
        return back == front && q[front] != -1;
    }
};
