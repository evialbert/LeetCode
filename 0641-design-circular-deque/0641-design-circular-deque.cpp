class MyCircularDeque {
public:
    //implementation using ciccular queues
    vector<int>deque;
    int front;
    int rear;
    int size;

    MyCircularDeque(int k) : deque(k + 1, -1), front(0), rear(0), size(k + 1) {
        
    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        deque[front] = value;
        if(front==0)
        {
            front = size-1;
        }
        else{
            front--;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }
        if(rear==size-1)
        {
            rear = 0;
        }
        else{
            rear++;
        }
        deque[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        if(front==size-1)
        {
            front = 0;
        }
        else{
            front++;
        }
        deque[front] = -1;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        deque[rear]=-1;
        if(rear==0)
        {
            rear = size - 1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(front==size-1)
        {
            return deque[0];
        }
        return deque[front+1];
    }
    
    int getRear() {
        return deque[rear];
    }
    
    bool isEmpty() {
        if(front==rear)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(front==0 && rear==size-1)
        {
            return true;
        }
        if(front==rear+1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */