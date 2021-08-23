class Solution {
    Map<Integer, Integer> memo = new HashMap<>();
    public int leastOpsExpressTarget(int x, int t) {  
        if(x == t) return 0;
        if(t == 1) return 1;
        if(memo.containsKey(t)) return memo.get(t);
        
        int count = 0;
        long res = x;
        while(res < t) {
            res *= x;
            count++;
        }
        
        //case 1: x*x*x...x - ()
        int ret1 = Integer.MAX_VALUE;
        if(res == t) {
            ret1 = count;
        } else if(res -t < t) {// make sure next target(res - t) is smaller than current target (t)
            ret1 = count + 1 + leastOpsExpressTarget(x, (int)(res - t));
        }

        //case 2: x*x*x...x + ()
        int ret2 = Integer.MAX_VALUE;
        res /= x;
        ret2 = leastOpsExpressTarget(x, (int)(t - res)) + (count == 0 ? 2 : count);
        
        int ret = Math.min(ret1, ret2);
        memo.put(t, ret);
        return ret;
    }
}