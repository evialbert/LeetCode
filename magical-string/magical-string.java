class Solution {
    public int magicalString(int n) {
      
        int[] A = new int[n+2];
        
        int fast=1;
        int slow=1;
        int num= 1;

        while(fast<=n){
            A[fast++] = num; 
            if (A[slow++]==2){
                A[fast++] = num;
            }
            num = 3-num;
        }
     
        int count=0;
        for(int j=1;j<=n;j++){
            if(A[j]==1)
                count++;
        }
        return count;            
        
    }
}