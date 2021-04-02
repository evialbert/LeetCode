class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        
        int result = 0;
        if(timeSeries.length == 0)
            return 0;
        if(timeSeries.length==1)
            return duration;
        
        for(int i=0;i<timeSeries.length-1;i++)
        {
            if(timeSeries[i]+duration < timeSeries[i+1])
                result = result + duration;
            else
            {
                result = result + (timeSeries[i+1] - timeSeries[i]); //The unit of time that is not overlapping with the next timeSeries alone is added here.
            }
        }
        
        //Add the last duration unit as it would be applicable for the last element under everycondition.
        return result+duration;
    }
}