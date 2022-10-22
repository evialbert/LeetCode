class Solution {
  public int minutesCost(int minutes, int startAt, int moveCost, int pushCost){
    int firstDigit = minutes / 10;
    int secondDigit = minutes % 10;
    
    int cost = 0;
    
    if (firstDigit == startAt){
        cost += pushCost;
    }
    else {
        cost += pushCost + moveCost;
    }
    
    if (secondDigit == firstDigit){
        cost += pushCost;
    }
    else {
        cost += pushCost + moveCost;
    }
    
    return cost;
} 

public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    
    int min = Integer.MAX_VALUE;
    
    if (targetSeconds < 10){
        int cost = pushCost;
        if (startAt != targetSeconds) cost += moveCost;
        
        return cost;
    }
    
    if (targetSeconds <= 99){
        int secondsCost = minutesCost(targetSeconds, startAt, moveCost, pushCost);
        
        min = secondsCost;
    }
    
    int optMin = targetSeconds/60;
    if (optMin > 99) optMin = 99;
    for (int i=0; i<=optMin; ++i){
        int secs = i*60;
        
        int diff = targetSeconds - secs;
        
        if (diff >=0 & diff <= 99){
            
            int initCost = 0;
            if (i < 10){
                if (i != startAt){
                    initCost = pushCost + moveCost;
                }
                else if (i != 0) initCost = pushCost;
            }
            else initCost = minutesCost(i, startAt, moveCost, pushCost);
            
            int secondsCost = minutesCost(diff, (i%10), moveCost, pushCost);
            
            int cost = initCost + secondsCost;
            
            min = Math.min(min, cost);
        }
    }
    
    return min;        
}
}