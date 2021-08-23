class Solution {
    public int maxWidthRamp(int[] A) {
        List<Integer> ls=new ArrayList<>();
        int res=0;
        for(int i=0;i<A.length;i++){
            if(ls.size()==0 || A[i]<A[ls.get(ls.size()-1)]){
                ls.add(i);
            }else{
                int left=0;
                int right=ls.size()-1;
                while(left<right){
                int mid=(left+right)/2;
                    if(A[i]<A[ls.get(mid)]){
                        left=mid+1;
                    }else{
                        right=mid;
                    }
                }
                res=Math.max(res,i-ls.get(left));
            }
        }
        System.out.println(ls);
               return res;
    }
}