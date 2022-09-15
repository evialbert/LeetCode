class Solution {
    public int minimumBuckets(String street) {
        int i = 0;
        int count = 0;
        while(i<street.length()){
            if(street.charAt(i)=='.'){
                i++;
                continue;
            }
            if(i!=street.length()-1 && street.charAt(i+1)=='.'){
                i+=3;
            }else if(i!=0 && street.charAt(i-1)=='.'){
                i+=1;
            }else{
                return -1;
            }
            count++;
        }
        return count;
    }
}