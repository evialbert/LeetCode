class Solution {
   public int[] findEvenNumbers(int[] digits) {
        int[] nf = new int[10]; // number frequency
        for(int a: digits)
        {
            nf[a]++;
        }
        List<Integer> result = new ArrayList<>();
        for(int i = 100;i<999;i+=2)
        {
            int[] tf = new int[10]; //temporary frequency
            int t = i;
            while(t>0)
            {
                tf[t%10]++;
                t /=10;
            }
            if(check(nf,tf)) result.add(i);
        }
        int[] res = new int[result.size()];
        for(int i = 0;i<result.size();i++)
        {
            res[i] = result.get(i);
        }
        return res;
    }
    
    boolean check(int[] nf, int[] tf)
    {
        for(int i = 0;i<10;i++)
        {
            if(tf[i]>nf[i])
                return false;
        }
        return true;
    }
}