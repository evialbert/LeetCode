class Solution {
    public double angleClock(int hour, int minutes) {
        int hourAngle = 0, minAngle = 0;
        double racingHour = 0.0;
        
        if(hour==12) hour = 0;
        
        double minTravel = 6 * minutes;
        int hourTravel = 30 * hour;
    
        racingHour = 0.5 * minutes; //with every minute, hour hand moves ahead by 0.5 degrees
        
        double totalHAngle = hourTravel + racingHour;
        
        double diff = Math.abs(minTravel - totalHAngle);
        
        if(diff > 180) 
		       diff = 360-diff;
        
        return diff;
    }
}