class Solution {
    public int[] threeEqualParts(int[] arr) {
        int countOne=0,n=arr.length;
        
        //count number of zeroes
        for(int i:arr)
            countOne+=i;
        
        //if all 0 return return (0, length)
        if(countOne==0)
            return new int[]{0,n-1};
        //if not divisible by 3 then return (-1,-1)
        if(countOne%3!=0)
            return new int[]{-1,-1};  
        
        
        
        int start = 0,mid = 0,end = 0;
        int averageOneCount=countOne/3;
        countOne=0;
        
        
        for(int i=0;i<n;i++){
            //skip all zeroes
            if(arr[i]==0)
                continue;
             
            //mark 1st 1 as start
            if(countOne==0)
                start=i;
            
            countOne++;   
            //find mid '1' element
           if(countOne == averageOneCount + 1) 
                mid = i;
            
            //find last '1' element
           if(countOne == 2 * averageOneCount + 1) 
                end = i;
            
        }
        
        //skip all elements which are same
        while(end < n && arr[start] == arr[mid] && arr[mid] == arr[end]){
            start++;
            mid++;
            end++;
        }
        
        //if we reach end then its possible so return (start-1,end)
        if(end == n) {
            return new int[]{start-1,mid};
        }
        
        //else return as its not possible
        return new int[]{-1,-1}; 
        
    }
}