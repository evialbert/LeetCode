class Solution {
    static class Pair{
        int eq,srq;
        Pair(int eq,int srq){
            this.eq=eq;
            this.srq=srq;
        }
    }
    public int minimumEffort(int[][] tasks) {
        List<Pair> list=new ArrayList<>();
        for(int[]row:tasks){
            list.add(new Pair(row[0],row[1]));
        }
        list.sort((a,b)->Integer.compare(b.srq-b.eq,a.srq-a.eq));
        int engery=0,ans=0;
        for(Pair cur:list){
            int act=cur.eq;
            int req=cur.srq;
            if(engery<req){
                ans+=(req-engery);
                engery=req;
            }
            engery-=act;
        }
        return ans;
    }
}