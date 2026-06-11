class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n = events.size();
        int score = 0;
        int counter = 0;
        for(int i = 0; i < n; i++) {
            if(counter == 10) break;
            if(events[i].size() == 1) {
                if(events[i] == "W") {
                    counter++;
                    continue;
                }
                else{
                    score += events[i][0]-'0';
                }
            }
            else score++;
        }
        return {score, counter};
    }
};