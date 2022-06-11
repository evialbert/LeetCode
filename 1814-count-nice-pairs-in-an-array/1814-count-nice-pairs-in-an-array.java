class Solution {
    public int countNicePairs(int[] nums) {
        Map<Integer, Integer> mp = new HashMap();
        Map<Integer, Integer> revm = new HashMap();
        int res = 0;
        int cst = 1000000007;
        for(int itm: nums){
            if(!revm.containsKey(itm))
                revm.put(itm, rev(itm));
			//a[i]+rev(a[j])= a[j]+rev(a[i]) => a[i]-rev(a[i])= a[j]-rev(a[j]
            int diff = itm-revm.get(itm);
            mp.put(diff, mp.getOrDefault(diff, 0)+1);
            res+=mp.get(diff)-1;
            res%=cst;
        }
        return res%cst;
    }
    
    public int rev(int nbr){
        int res = 0;
        while(nbr!=0){
            res*=10;
            res+=nbr%10;
            nbr/=10;
        }
        return res;
    }
}