class MyCircularDeque {
    int[] arr;
    int front = 0, rear =-1, len =0, size;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        arr = new int[k];
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if(!isFull()) {
            front = (front - 1 + size) % size;
            arr[front] = value;
            len ++;
            if(len == 1)
                rear =front;
            return true;
        }        
        else {
            return false;
        }
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if(!isFull()) {
            rear = (rear + 1) % size;
            arr[rear] = value;
            len ++;
            return true;
        }        
        else {
            return false;
        }
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if(!isEmpty()) {
            front = (front + 1) % size;
            len --;
            return true;
        }        
        else {
            return false;
        }
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if(!isEmpty()) {
            rear = (rear -1) % size;
            if(rear < 0)
                rear += size;
            len --;
            return true;
        }
        else {
            return false;
        }
        
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        return isEmpty() ? -1 : arr[front];        
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        return isEmpty() ? -1 : arr[rear];
        
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return len == 0;        
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return len == size;        
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */