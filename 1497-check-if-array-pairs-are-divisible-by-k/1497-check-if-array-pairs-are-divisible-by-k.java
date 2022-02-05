class Solution {
    public boolean canArrange(int[] arr, int k) {
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            int rem=((arr[i]%k)+k)%k;
            map.put(rem,map.getOrDefault(rem,0)+1);
        }
        for(int i=0;i<arr.length;i++){
            int r=arr[i]%k;
            if((r==0)){
                if(map.get(r)%2!=0){
                    return false;
                }
            }else if(2*r==k){
                if(map.get(r)%2!=0){
                    return false;
                }
            }
            else{
                int fq=map.getOrDefault(r,0);
                int ofq=map.getOrDefault(k-r,0);
                if(fq!=ofq){
                    return false;
                }
            }
        }
        return true;
    }
}