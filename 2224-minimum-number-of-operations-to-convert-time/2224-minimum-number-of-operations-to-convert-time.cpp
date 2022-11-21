class Solution {
public:
    int convertTime(string current, string correct) {
        int hours1=stoi(current.substr(0,2));
        int hours2=stoi(correct.substr(0,2));
        int min1=stoi(current.substr(3,2));
        int min2=stoi(correct.substr(3,2));
        int mins=((60-min1)+(min2))<60?abs((hours2-hours1-1)*60)+((60-min1)+(min2)):abs((hours2-hours1)*60) + abs(min2-min1);
        int count=0;
        while(mins!=0){
            if(mins>=60){
                count++;mins-=60;
            }
            else if(mins>=15){
                count++;mins-=15;
            }
            else if(mins>=5){
                count++;mins-=5;
            }
            else if(mins>=1){
                count++;mins-=1;
            }
        }
        return count;
        
    }
};