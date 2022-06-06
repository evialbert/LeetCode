class Solution {
    public int minOperations(int[] nums1, int[] nums2) {
        long sum1 = Arrays.stream(nums1).sum();
        long sum2 = Arrays.stream(nums2).sum();
        LinkedList<Integer> n1 = new LinkedList<Integer>();
        LinkedList<Integer> n2 = new LinkedList<Integer>();
        n1.addAll(Arrays.stream(nums1).boxed().collect(Collectors.toList()));
        n2.addAll(Arrays.stream(nums2).boxed().collect(Collectors.toList()));
        if(sum1 > sum2) {
            //swap
            LinkedList<Integer> a = n1;
            n1 = n2;
            n2 = a;
        }
        Collections.sort(n1);
        Collections.sort(n2, Collections.reverseOrder());
        long diff = Math.abs(sum2 - sum1);
        int count = 0;
        while(diff > 0) {
            int s1 = n1.size() > 0 ? n1.get(0) : 6;
            int l1 = n2.size() > 0 ? n2.get(0) : 1;
            int d = Math.max(6 - s1, l1 - 1);
            if(d == 0)
                return -1;

            if(6 - s1 > l1 - 1) {
                n1.poll();
            } else {
                n2.poll(); 
            }
            diff -= d;
            count += 1;
        }
        return count;
    }
}