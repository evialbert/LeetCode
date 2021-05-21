class Solution {
    public int maxChunksToSorted(int[] arr) {
        
        if(arr.length==0) return 0;
        int[] maxfromstart=new int[arr.length];
        int[] minfromlast=new int[arr.length];
         
        maxfromstart[0]=arr[0];
        for(int i=1;i<arr.length;i++){
            if(arr[i]>maxfromstart[i-1]){
                maxfromstart[i]=arr[i];
            }else{
                maxfromstart[i]=maxfromstart[i-1];
            }
        }
        
        minfromlast[arr.length-1]=arr[arr.length-1];
        for(int i=arr.length-2;i>=0;i--){
            if(arr[i]<minfromlast[i+1]){
                minfromlast[i]=arr[i];
            }else{
                minfromlast[i]=minfromlast[i+1];
            }
        }
        
        int chunk=1; 
        for(int i=0;i<arr.length-1;i++){
            if(maxfromstart[i]<=minfromlast[i+1]){
                chunk++;
            }
        }
        return chunk;
    }
}