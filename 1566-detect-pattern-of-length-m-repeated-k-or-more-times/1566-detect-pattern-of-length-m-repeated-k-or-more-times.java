class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
             
        for(int i=0;i<arr.length-m;i++)
        {
            int temp=1;
            int arr1[] = Arrays.copyOfRange(arr,i,i+m);
            for(int j=i+m;j<arr.length;j+=m)
            {
                int arr2[] = Arrays.copyOfRange(arr,j,j+m);
                if(Arrays.equals(arr1,arr2))
                    temp++;
                else break;
            }
            if(temp >= k) 
                return true;
        }
        return false;
    }
}