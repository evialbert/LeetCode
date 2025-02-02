class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int, int>> times;
        for(int i=0; i<startTime.size(); i++) times.push_back(make_pair(startTime[i], endTime[i]));
        sort(times.begin(), times.end());
        int longestTime = 0;
        int totaltimeinWindow = 0;
        int left = 0;
        for(int i=0; i<times.size(); i++){
            totaltimeinWindow += (times[i].second - times[i].first);
            if(i > (k - 1)){ totaltimeinWindow -= (times[left].second - times[left].first); left++;}
            int leftbound = (left - 1) < 0 ? 0 : times[left - 1].second;
            int rightbound = i + 1 < times.size() ? times[i + 1].first : eventTime;
            longestTime = max(longestTime, max(rightbound - (leftbound + totaltimeinWindow), (rightbound - totaltimeinWindow) - leftbound));
        }
        return longestTime;
    }
};