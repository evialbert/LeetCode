class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int max = -2;
        for(int num : dist) max = Math.max(max, num*1000);
        int min = 1;
        double sum = 0.0;
        int k = 0;
        int lastCorr = -1;
        while(min <= max){
            k = (max - min) / 2 + min;  
            sum = 0.0;
            for(int num = 0 ; num < dist.length; ++num){
                if(num == dist.length - 1){
                    sum += (double) ((double) dist[num])/(k+0.0);
                    if(sum <= hour) lastCorr = k;
                }
                else{
                    sum += (int) dist[num]/k;
                    if(dist[num] % k != 0) sum += 1;
                    
                }
                if(sum > hour){
                    break;
                }
            }
            if(hour == sum) return k;
            else if(sum > hour){
                min = k+1;
            }
           else {
                max = k-1;
            }    
        }
        return (hour == sum) ? k : lastCorr;
    }
}