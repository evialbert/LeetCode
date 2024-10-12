class Solution {
    public int minGroups(int[][] intervals) {
        int[] cnt = new int[1_000_002];
        for(var i:intervals){
            cnt[i[0]]++;
            cnt[i[1]+1]--;
        }


        int maxi=0, temp=0;
        for(int c:cnt){
            temp += c;
            maxi = Math.max(maxi, temp);
        }
        return maxi;
    }
}