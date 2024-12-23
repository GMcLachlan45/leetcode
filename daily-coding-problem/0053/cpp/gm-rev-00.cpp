#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept>

template <typename T> class queue {
private:
    std::stack<T> nq;
    std::stack<T> dq;

public:
    T dequeue() {
        while(!nq.empty()) {
            dq.push(nq.top());
            nq.pop();
        }
        if(dq.empty())
            throw std::runtime_error("The queue is empty!");
        T ret = dq.top();
        dq.pop();
        return ret;
    };

    void enqueue(T elem) {
        while(!dq.empty()) {
            nq.push(dq.top());
            dq.pop();
        }
        nq.push(elem);
    };
    void print() {
        while(!nq.empty()) {
            dq.push(nq.top());
            nq.pop();
        }
        std::cout<< "Current Queue:" <<std::endl;
        while(!dq.empty()) {
            std::cout<< dq.top()<<" ";
            nq.push(dq.top());
            dq.pop();
        }
        std::cout<<std::endl;
    };
};



int main() {
    std::vector<int> input = {5, 4, 3, 1, 2};
    queue<int> q;
    for(auto x : input) {
        q.enqueue(x);

    }
    q.dequeue();
    q.dequeue();
    q.enqueue(12);
    q.print();
}
