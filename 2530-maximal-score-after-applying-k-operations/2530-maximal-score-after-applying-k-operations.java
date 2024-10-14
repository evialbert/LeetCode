class Solution {
    public long maxKelements(int[] nums, int k) {

        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b - a);

        for(int ele:nums){ // n logn

            pq.add(ele);

        }
        
        long score = 0;

        while(k > 0){

            int re_ele = pq.peek();

            pq.remove();

            score += re_ele;

            pq.add((int)Math.ceil(re_ele/3.0));

            k--;

        }

        return score;
    }
}