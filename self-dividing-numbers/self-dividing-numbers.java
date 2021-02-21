class Solution {
    public static List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> L = new ArrayList<>();
        int div = 0;
        int rem = 0;
        for(int i=left; i<=right; i++)
        {
            int tmp = i;
            int tmp2 = i;
            do{
                rem = tmp2 % 10;
                if(rem == 0)
                    break;
                if(tmp % rem != 0)
                    break;
                tmp2 /= 10;
            }while(tmp2 != 0);
            if(tmp2 == 0)//yes
                L.add(tmp);
        }
        return L;
    }
}