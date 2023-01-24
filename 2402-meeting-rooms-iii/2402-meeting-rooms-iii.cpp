class Solution {
    
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int mostBooked(int n, vector<vector<int>>& a) {
        long long finishTime[105] = {};
        long long cnt[105] = {};
        int ans, maxCount = 0;
        fill(finishTime, finishTime + 105, 0);
        
        sort(a.begin(), a.end(), comp);
        for (int i = 0; i < a.size(); i++) {
            long long hasFreeRoom = 0, minFinish = 1e18, selectedRoom = 0;
            for (int room = 0; room < n; room++) {
                if (finishTime[room] < minFinish) {
                    minFinish = finishTime[room];
                    selectedRoom = room;
                }
                if (finishTime[room] <= a[i][0]) {
                    hasFreeRoom = 1;
                    selectedRoom = room;
                    break;
                }
            }
            if (hasFreeRoom) finishTime[selectedRoom] = a[i][1];
            else finishTime[selectedRoom] = finishTime[selectedRoom] - a[i][0] + a[i][1];
            cnt[selectedRoom]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (cnt[i] > maxCount) {
                ans = i;
                maxCount = cnt[i];
            }
        }
        
        return ans;
    }
};