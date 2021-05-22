class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        
        //create min heap; max heap does not work for this question
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[1] == b[1] ? a[0] - b[0] : a[1]-b[1]);
        
        for(int i : arr) {
            int[] array = new int[2];
            array[0] = i;
            array[1] = Math.abs(x-i);
           
            pq.add(array);
        }
        
        List<Integer> res = new ArrayList<Integer>();
        
        
        for(int i=0; i < k; i++) 
            res.add(pq.poll()[0]);
        
        
        Collections.sort(res);
        
        return res;
                
    }
}