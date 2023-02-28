class DataStream {
public:
    int n,max;
    DataStream(int value, int k) {
        n = value;
        max = k;
    }
    int cnt = 0;
    bool consec(int num) {
        if(num==n) cnt++;
        else if(num != n) cnt= 0;
        if(cnt>=max) 
            return true;
        return false;
    }
};


/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */