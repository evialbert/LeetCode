class Solution {
    public int minDeletionSize(String[] A) {
        int len = A.length;
        int slen = A[0].length();
        int cnt = 0;
        boolean[] valid = new boolean[len];
        for(int i=0; i<slen; i++){
            List<Integer> list = new ArrayList();
            for(int j=0; j<len-1; j++){
                if(valid[j]) continue;
                char cur = A[j].charAt(i);
                char next = A[j+1].charAt(i);
                if(cur < next)
                    list.add(j);
                else if(cur > next){
                    cnt++;
                    list = new ArrayList();
                    break;
                }
            }
            for(int n : list) valid[n]=true;
        }
        return cnt;
    }
}