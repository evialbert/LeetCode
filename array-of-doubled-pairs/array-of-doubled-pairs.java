class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        Arrays.sort(arr);
        for(int i=0; i<arr.length; i++)
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        
        if(map.get(0)!=null && map.get(0)%2!=0)
            return false;
        
        int count = map.getOrDefault(0, 0);
        map.put(0, 0);
        for(int i=arr.length-1; i>=0; i--) {
            Integer t1 = map.get(arr[i]);
            Integer t2 = map.get(arr[i]*2);
            if(t1!=null && t2!=null){
                //System.out.println(arr[i]+" "+(arr[i]*2));
                if(t1==0 || t2==0)
                    continue;
                map.put(arr[i], t1-1);
                map.put(arr[i]*2, t2-1);
                count+=2;
            }
        }
    
        return count==arr.length;
    }
}