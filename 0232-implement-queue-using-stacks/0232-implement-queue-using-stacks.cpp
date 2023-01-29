class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        while (!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int val= stk2.top();
        stk2.pop();
        while (!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return val;
    }
    
    int peek() {
        while (!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int top_el= stk2.top();
        while (!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return top_el;
    }
    
    bool empty() {
        return stk1.empty();
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