class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int prev = 0;
        for (int i = 1; i < colors.size(); i++){
            if (colors[i] == colors[prev]){
                if (neededTime[i] < neededTime[prev]){
                    time += neededTime[i];
                } else {
                    time += neededTime[prev];
                    prev = i;
                }
            } else {
                prev = i;
            }
        }
        return time;
    }
};