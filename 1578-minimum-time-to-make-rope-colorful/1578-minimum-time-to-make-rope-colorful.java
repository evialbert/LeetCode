class Solution {
    public int minCost(String colors, int[] neededTime) {
        char prev = colors.charAt(0); 
        int prevTime = neededTime[0]; 
        int i = 1; 
        int time = 0; 
        
        while (i < colors.length()) { 
            if (prev == colors.charAt(i)) { 
                time += Math.min(prevTime, neededTime[i]); 
                prevTime = Math.max(prevTime, neededTime[i]);
            } else { 
                prev = colors.charAt(i); 
                prevTime = neededTime[i]; 
            }
            i++;
        }
        return time;
    }
}