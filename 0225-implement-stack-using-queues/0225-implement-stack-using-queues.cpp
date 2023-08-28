class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sz=q.size();
        q.push(x);
        for(int i=0;i<sz;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) return true;
        return false;
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */