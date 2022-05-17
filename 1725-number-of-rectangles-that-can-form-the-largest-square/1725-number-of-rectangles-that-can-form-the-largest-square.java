class Solution {
    public int countGoodRectangles(int[][] rectangles) {
      int count=0,max=0,diff;
        for(int i=0;i<rectangles.length;i++)
        {
            if(rectangles[i][0]<rectangles[i][1])
            {
                diff=rectangles[i][0];
            }
            else
            {
                diff=rectangles[i][1];
            }
            if(diff==max)
            {
                count++;
                
            }
            if(diff>max)
            {
                count=1;
                max=diff;
            }
       
            
        }
        return count;
    }
}