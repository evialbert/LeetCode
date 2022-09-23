class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        Queue<Pair> first = new PriorityQueue<>((a, b) -> a.value - b.value);//sort based on value in "first" Queue
        for(int i = 0; i < nums.length; i++){
            first.add(new Pair(nums[i], i));
            if(first.size() > k) first.remove();
        }
        
        Queue<Pair> second = new PriorityQueue<>((a, b) -> a.index - b.index);//sort based on index in "second" Queue
        while(!first.isEmpty()){
            int x = first.peek().value;
            int y = first.remove().index;
            second.add(new Pair(x, y));
        }
        int ans[] = new int[k];
        int x = 0;
        while(!second.isEmpty()){
            ans[x++] = second.remove().value;
        }
        return ans;
    }
}

class Pair{
    int value;
    int index;
    Pair(int value, int index){
        this.value = value;
        this.index = index;
    }
}