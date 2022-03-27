class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int maxIndex=0;
        int maxValue=releaseTimes[0];
        for(int i=1;i<releaseTimes.length;i++){
            int check=releaseTimes[i]-releaseTimes[i-1];
            if(check>maxValue){
                maxValue=check;
                maxIndex=i;
            }else if(check==maxValue){
                if(keysPressed.charAt(i)>keysPressed.charAt(maxIndex))
                    maxIndex=i;
            }
        }
        
        return keysPressed.charAt(maxIndex);
    }
}