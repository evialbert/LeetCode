class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        while(start && goal){
            if(start%2!=goal%2) count++;
            start/=2;
            goal/=2;
        }
        while(start){
            if(start%2)count++;
            start/=2;
        }
        while(goal){
            if(goal%2)count++;
            goal/=2;
        }
        return count;
    }
};