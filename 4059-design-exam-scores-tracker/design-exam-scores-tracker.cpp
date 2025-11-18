class ExamTracker {
    vector<long long> ps;
    vector<int> t;

public:
    ExamTracker() { ps = {0}; }

    void record(int time, int score) {
        t.push_back(time);
        ps.push_back(0LL + ps.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        int i1 = lower_bound(t.begin(), t.end(), startTime) - t.begin();
        int i2 = upper_bound(t.begin(), t.end(), endTime) - t.begin() ;
        return ps[i2 ] - ps[i1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */