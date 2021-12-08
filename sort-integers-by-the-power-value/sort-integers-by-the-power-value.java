class Solution {
    public int getKth(int lo, int hi, int k) {
        HashMap<Integer, Integer> map = new HashMap();
        
		// find the steps and store it into map
        for(int i=lo; i<=hi; i++){
            int res = findPow(i, 0);
            map.put(i, res);
        }
        
        List<Integer> l = new ArrayList<Integer>(map.keySet());
        
        Collections.sort(l, (a,b) -> {
			// compare the steps if they are not equal then return the minimum
            if(map.get(a) != map.get(b)){
                return map.get(a) - map.get(b);
            }
			// if both element take same steps then return the min of them
            return a - b;
        });
        
        return l.get(k-1);  // return the kth element
    }
    int findPow(int x, int steps){
        if(x == 1) return steps;
        
        if(x % 2 == 0) {
            return findPow(x/2, steps+1);
        } else {
            return findPow(3*x+1, steps+1);
        }
    }
}