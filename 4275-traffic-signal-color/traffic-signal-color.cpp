class Solution {
public:
    string trafficSignal(int timer) {
        if(timer==0)return "Green";
        if(timer==30)return "Orange";
        if(timer<=90 && timer>30)return "Red";
        else
        return "Invalid";
    }
};