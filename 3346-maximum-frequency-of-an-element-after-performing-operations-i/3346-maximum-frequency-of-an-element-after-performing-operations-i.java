class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        HashMap<Integer,Integer>map=new HashMap<>();
       List<int[]>temp=new ArrayList<>();
        for(int x:nums){
            map.put(x,map.getOrDefault(x,0)+1);
            temp.add(new int[]{x-k,1});
            temp.add(new int[]{x+k+1,-1});
        }
        Set<Integer>st=new TreeSet<>();
        for(int j[]:temp){
            st.add(j[0]);
        }
        for(int key_:map.keySet()){
            st.add(key_);
        }
        temp.sort(Comparator.comparingInt(a ->a[0]));
         int i = 0, curr = 0, max_freq = 0;
        
        for (int x : st) {
            while (i < temp.size() && temp.get(i)[0] <= x) {
                curr += temp.get(i)[1];
                i++;
            }
            
            int base_cnt = map.getOrDefault(x, 0);
            int freq = base_cnt + Math.min(numOperations, curr - base_cnt);
            max_freq = Math.max(max_freq, freq);
        }
        
        return max_freq;
    }
    
}