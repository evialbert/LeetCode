class Solution {
  public int[] frequencySort(int[] nums) {
         Map<Integer, Integer> map= new HashMap<>();
        Queue<Integer> heap = new PriorityQueue<>((a,b)->
        {
		//if frequencies same, compare values and return in descending order
            if(map.get(a)==map.get(b))
              return b-a;
			  //otherwise return based on frequency
            else return map.get(a)-map.get(b);
        });
        
       
        for(int i:nums){
            map.put(i, map.getOrDefault(i, 0)+1);
        }
        
        int [] res= new int[nums.length];
        for(int i:map.keySet()){
            heap.add(i);
        }
        
        int j=0;
        while(!heap.isEmpty()){
            int temp=heap.poll();
            for(int i=0;i<map.get(temp);i++){
                res[j]=temp;
                j++;
            }
        }
        return res;
    }
}