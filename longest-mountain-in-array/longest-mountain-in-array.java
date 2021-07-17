class Solution {
    public int longestMountain(int[] arr) {
        int largest=0;
        int n=arr.length;
        for(int i=1; i<= n-2 ;){
            //check a[i] is peak or not
            if(arr[i] > arr[i+1] && arr[i]>arr[i-1]){
                int count=1;
                int  j =i;
                //then count backwards(left)
                while(j >= 1 && arr[j] > arr[j-1]){
                    j--;
                    count++;
                }
                 //then count forwards(right)
                while(i <= n-2 && arr[i] > arr[i+1]){
                    i++;
                    count++;
                    
                }
                largest=Math.max(largest , count);
            }
            else
                i++;
        }
        return largest;
    }
}