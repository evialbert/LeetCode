class TweetCounts {
private:
    map <string, multiset <int>> tweetTimeline;
    unordered_map <string, int> freqEnum;
public:
    TweetCounts() {
        freqEnum["minute"] = 60;
        freqEnum["hour"] = 60 * freqEnum["minute"];
        freqEnum["day"] = 60 * freqEnum["hour"];
    }
    
    void recordTweet(string tweetName, int time) {
        tweetTimeline[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int intervals = ((endTime - startTime) /  freqEnum[freq]) + 1;
        vector <int> tweetCountsPerFrequency(intervals, 0);
        
        auto tweetClosestToStartTimeItr = tweetTimeline[tweetName].lower_bound(startTime);   
        auto tweetClosestToEndTimeItr = tweetTimeline[tweetName].upper_bound(endTime);
        
        for(auto it = tweetClosestToStartTimeItr; it != tweetClosestToEndTimeItr; it++) {
            int idx = (*it - startTime) / freqEnum[freq]; // see which frequency interval my current time lies in
            tweetCountsPerFrequency[idx]++;
        }
        
        return tweetCountsPerFrequency;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */