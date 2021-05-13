// here the modulo operator will help us to reuse the positions in array. for ex 
//if we have 3 elements array 1,2,3 then front is at position 0 size is 3 capacity is 3.
//now if we delete one element so 1 will be deleted
//(as deletion is done from front end in queue), and front becomes 1(index 1)
//and the index 0 remain unused to use this space we took the help of modulo % operator .

class MyCircularQueue {
    int [] arr;
    int front;
    int size;
    int capacity;
    public MyCircularQueue(int k) { 
// k is capacity and size is current number  of elements present in array
        capacity = k;
        arr = new int[k];
        front = 0;
        size = 0;
    }
    
    public boolean enQueue(int value) {
        if(size == capacity){ // if size(number of elements  == capacity)
            return false;
        }else{
            
            arr[(front + size) % capacity]  = value;
            size++;
            return true;
        }
    }
    
    public boolean deQueue() {
        if(size == 0){
            return false;
        }else{
              size--;
            front++;
           front = (front % capacity);
            return true;
        }
    }
    
    public int Front() {
        if(size == 0){
            return - 1;
        }
        return arr[front];
    }
    
    public int Rear() {
        if(size == 0){
            return - 1;
        }else{
            int idx = (front + size - 1) % capacity;
            return arr[idx];
        }
    }
    
    public boolean isEmpty() {
        if(size == 0){
            return true;
        }
        return false;
    }
    
    public boolean isFull() {
        if(size == capacity){
            return true;
        }
        return false;
    }
}
