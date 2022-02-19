class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c)
    {
      int i,j,k,count=0;
      for(i=0;i<(arr.length)-2;i++)
        for(j=i+1;j<(arr.length)-1;j++)
          if(Math.abs(arr[i]-arr[j]) <=a)
            for(k=j+1;k<arr.length;k++){
             if(Math.abs(arr[j]-arr[k]) <=b)
               if(Math.abs(arr[i]-arr[k]) <=c)
                  count++;
          }
      return count;
    }
}