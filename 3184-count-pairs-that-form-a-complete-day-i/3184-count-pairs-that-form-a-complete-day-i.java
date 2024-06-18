class Solution {
    public int countCompleteDayPairs(int[] hours) {
       int n=hours.length;
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=hours[i]+hours[j];
                if(sum%24==0)count++;
            }
        }
        return count;
    }
}