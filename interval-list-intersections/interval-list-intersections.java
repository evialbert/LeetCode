class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int m = firstList.length,n=secondList.length;
        int i=0,j=0;
        int[][] ans = new int[5000][]; int pos=0;
        while(i<m&&j<n){
            int l = Math.max(firstList[i][0], secondList[j][0]);
            int r = Math.min(firstList[i][1], secondList[j][1]);
            if(l<=r){
                ans[pos] = new int[]{l,r};
                pos++;
            }
            if(firstList[i][1] < secondList[j][1])
                i++;
            else if(firstList[i][1] > secondList[j][1])
                j++;
            else{
                i++;
                j++;
            }
        }
        return Arrays.copyOf(ans,pos);
    }
}