//JAVA Greedy Solution O(1)
class Solution {
    public int videoStitching(int[][] clips, int time) {
        Arrays.sort(clips,(a,b)->(a[0]-b[0]));
        int farthermost=0,end=0,count=0,i=0;
        while(end<time)
        { count++;
            while(i<clips.length && clips[i][0]<=end)
            {  farthermost=Math.max(farthermost,clips[i][1]);
               i++;
               
            }
            if(end==farthermost)return -1;
            end=farthermost;
                
        }
        
        return count;
    }
}