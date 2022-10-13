class Solution {
    public int minMoves(int t, int md) {
        int count=0;
        if(md==0){
            return t-1;
        }
        while(t!=1){
            if(t%2==0 && md>0){
                t/=2;
                md--;
                count++;
            }
            else if(t>1 && md==0){
                count+=t-1;
                t=1;
                md--;
            }
            else{
                t--;
                count++;
            }
        }
        return count;

}
}