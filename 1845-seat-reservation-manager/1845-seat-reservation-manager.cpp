class SeatManager {
public:
    priority_queue<int> s;
    int cnt = 1;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(s.empty())
            return cnt++;
        int x = s.top();s.pop();
        return -x;
    }
    
    void unreserve(int seatNumber) {
        s.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */