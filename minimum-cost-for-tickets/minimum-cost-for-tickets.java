class Solution {
    public int floor(int[] days,int x){
        if(x<=0)
            return -1;
        int ans = 1000;
        int low = 0;
        int high = days.length;
        while(low<=high){
            int mid = (low+high)/2;
            if(days[mid]<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(ans>=1000)
            return -1;
        return ans;
        
    }
    public int mincostTickets(int[] days, int[] costs) {
        int dp[] = new int[days.length];
        int c1=costs[0];
        int c7=costs[1];
        int c30=costs[2];
        dp[0]=Math.min(c1,Math.min(c7,c30));
        for(int i=1;i<days.length;i++){
            int firstcase = c30;
            int secondcase = c7;
            int thirdcase = c1;
            if((days[i]-30)>0 && floor(days,days[i]-30)>=0)
                firstcase+=dp[floor(days,days[i]-30)];
            if((days[i]-7)>0 && floor(days,days[i]-7)>=0)
                secondcase+=dp[floor(days,days[i]-7)];
            if(days[i]-1>=0 && floor(days,days[i]-1)>=0)
                thirdcase+=dp[floor(days,days[i]-1)];
            dp[i]=Math.min(firstcase,Math.min(secondcase,thirdcase));
        }
        return dp[days.length-1];
    }
}