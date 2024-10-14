#include <stack>

class MyQueue {
public:
    std::stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int element = 0;
        if(s1.empty()) return -1;

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        element = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return element;
    }
    
    int peek() {
        int element = 0;
        if(s1.empty()) return -1;

        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        element = s2.top();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return element;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */