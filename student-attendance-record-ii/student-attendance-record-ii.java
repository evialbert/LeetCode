class Solution {
    public int checkRecord(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 3;
        if(n == 2)
            return 8;
        long res_0 =0L;
        long res_1 = 0L;
        long N_1_0 = 4L;long N_1_1 = 8L;long N_2_0 = 2L;long N_2_1 = 3L;long N_3_0 = 1L;long N_3_1 = 1L;
        for(int i = 3;i<= n;i++){
            res_0 = (N_1_0 + N_2_0 + N_3_0)%1000000007L;
            res_1 = (N_1_0 + N_2_0 + N_3_0 + N_1_1 + N_2_1 + N_3_1)%1000000007L;
            N_3_0 = N_2_0;
            N_2_0 = N_1_0;
            N_1_0 = res_0;
            N_3_1 = N_2_1;
            N_2_1 = N_1_1;
            N_1_1 = res_1;
        }
        return (int) res_1;
    }
}