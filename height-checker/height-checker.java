class Solution {
    
    //the fastest way is cloning the array, 
    //sort it and compare with the original.
    public int heightChecker(int[] heights) {
        int count = 0;
        int[] temp = heights.clone();
        Arrays.sort(temp);
        for(int i=0;i<heights.length;i++){
            if(temp[i] != heights[i]) count++;
        }
        return count;
    }
    
    //seems like my heap solution is super slow... 
    public int heightChecker_(int[] heights) {
        int count = 0;
        Queue<Integer> heap = new PriorityQueue<>();
        for(int i: heights) heap.add(i);
        for(int i: heights){
            int temp = heap.poll();
            if(temp != i) count++;
        }
        return count;
    }
}