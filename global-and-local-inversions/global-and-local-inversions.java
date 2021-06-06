class Solution {
   int global=0;
    public boolean isIdealPermutation(int[] arr) {
       int local=0;
        for(int i=0;i<arr.length-1;i++){
          if(arr[i]>arr[i+1]) local++;
        }
      mergeSort(arr,0,arr.length-1);
      System.out.println(local);
      System.out.println(global);
      return local==global;
    }
   public int[] mergeSort(int arr[],int l,int h){
        if(l==h){
            return new int[]{arr[l]};
        }
        int mid=l+(h-l)/2;
        int lsh[] = mergeSort(arr,l,mid);
        int rsh[] = mergeSort(arr,mid+1,h);
        int fsh[] = merger(lsh,rsh);
        return fsh;
    }
    public int[] merger(int left[], int right[]){
        int arr[] = new int[left.length+ right.length];
        int idx=0;
        int i=0;
        int j=0;
        while(i<left.length && j<right.length){
            if(left[i]<=right[j]){
                arr[idx]=left[i];
                i++;
                idx++;
                
            }
            else{
               global+=(left.length-i);
                arr[idx]=right[j];
                idx++;
                j++;
            }
        }
        while(i<left.length){
            arr[idx++]=left[i++];
        }
            while(j<right.length){
            arr[idx++]=right[j++];
        }
        return arr;
    }
}