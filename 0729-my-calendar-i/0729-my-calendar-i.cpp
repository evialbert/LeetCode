class MyCalendar {
public:
    //declare pair booking vector
    vector<pair<int,int>> booking;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //check for all possible pairs which are present inside the booking
        for(auto it: booking){
            //if start and end range is between of any pair which is already present inside booking then return false
            if(max(start,it.first)<min(end,it.second)){
                return false;
            }
        }
        //if we reach hear it means current start and end pair is not booked then store this pair inside the booking
        booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */