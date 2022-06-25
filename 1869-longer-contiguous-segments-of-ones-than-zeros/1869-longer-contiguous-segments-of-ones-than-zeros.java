class Solution {
    public boolean checkZeroOnes(String s) {
        
        int ones = 0;
        int zeros = 0;
        int zerosMax = 0;
        int onesMax = 0;
        
        char arr[] = s.toCharArray();
        
        for(int i=0; i<arr.length; i++){
            if(arr[i]=='0'){
                zeros++;
                if(zerosMax<zeros){
                    zerosMax=zeros;
                }
            }else{
                zeros = 0;
            }
        }
        
        for(int i=0; i<arr.length; i++){
            if(arr[i]=='1'){
                ones++;
                if(onesMax<ones){
                    onesMax=ones;
                }
            }else{
                ones = 0;
            }
        }
      
        return onesMax>zerosMax;
    }
}