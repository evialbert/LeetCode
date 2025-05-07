class MedianFinder {
public:
    priority_queue <int, vector<int>, greater<int>> maxarr;//minheap
    priority_queue <int> minarr;//maxheap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minarr.push(num);
        //the largest element in the minimum array is greater than the smallest element in max array
        if(minarr.size()!=0 and maxarr.size()!=0 and (minarr.top()> maxarr.top())){
            maxarr.push(minarr.top());
            minarr.pop();
        }
        //Size diff > 2
        if(minarr.size() > maxarr.size()+1){
            maxarr.push(minarr.top());
            minarr.pop();
        } 
        //size diff > 2 other way
        if(minarr.size()+1 < maxarr.size()){
            minarr.push(maxarr.top());
            maxarr.pop();
        }
    }
    
    double findMedian() {
        if(minarr.size() > maxarr.size()){
            //odd size
            return minarr.top();
        }
        if(minarr.size() < maxarr.size()){
            //odd size other way
            return maxarr.top();
        }
        //even case
        return (double)(minarr.top()+maxarr.top())/(double)2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */