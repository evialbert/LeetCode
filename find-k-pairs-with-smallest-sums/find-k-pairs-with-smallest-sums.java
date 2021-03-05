class Solution {
    
    /**
      1. Create a Min Heap and put first element of Heap of second array wioth all elements of first array .
      2. then move to next element of secodn array until it reaches K
    
    **/
    
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        
        if( nums1== null || nums1.length==0 || nums2== null || nums2.length==0 ){
            return new ArrayList<>();
        }
        List<List<Integer>> answer = new ArrayList<>();
        PriorityQueue<Pair<Integer,Node>> minHeap = new PriorityQueue<>((obj1, obj2)-> obj1.getKey()-obj2.getKey());
        
        // lets iterate first nums1
        for( int i =0 ; i < nums1.length ; i++){
            Pair<Integer,Node> obj = new Pair<>(nums2[0]+nums1[i],new Node(i,0));
            minHeap.offer(obj);
        }
        
        while(!minHeap.isEmpty()){
            Pair<Integer,Node> element = minHeap.poll();
            int num1Index = element.getValue().num1Index;
            List<Integer> pair = new ArrayList<>();
            pair.add(nums1[num1Index]);
            pair.add(nums2[element.getValue().num2Index]);
            answer.add(pair);
            k--;
            if( k ==0){
                return answer;
            }
            int newNum2Index = element.getValue().num2Index +1;
            if(newNum2Index < nums2.length){
                Pair<Integer,Node> obj = new Pair<>(nums2[newNum2Index]+nums1[num1Index],new Node(num1Index,newNum2Index));
                minHeap.offer(obj); 
            }
           
        }
        return answer;
        
    }
}
class Node {
    int num1Index;
    int num2Index;
    public Node( int num1Index, int num2Index){
        this.num1Index = num1Index;
        this.num2Index = num2Index;
    }
    
}