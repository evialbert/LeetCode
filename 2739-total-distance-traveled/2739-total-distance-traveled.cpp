class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0;
        if(mainTank<5){
            int res=mainTank%5;
            return (res*10);
        }
        while (mainTank > 0 || additionalTank > 0) {
            if (mainTank >= 5) {
                distance += 50;
                mainTank -= 5;
                if(additionalTank>0){
                    mainTank += 1;
                    additionalTank -= 1;
                }
            } 
            else{
                int res=mainTank%5;
                distance=distance+(res*10);
                break;
            }
        }
        return distance;
    }
};