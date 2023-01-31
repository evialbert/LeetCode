class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int longest = logs[0][1];
        int id = logs[0][0];
        int end = logs[0][1];
        
        for(int i = 1; i < logs.size(); i++) {
            int duration = logs[i][1] - end;
            
            if(duration > longest || (duration == longest && logs[i][0] < id)) {
                id = logs[i][0];
                longest = duration;
            } 
            end = logs[i][1];
        }
        return id;
    }
};