class Solution {
    public int maxGoodNumber(int[] nums) {
        int n1 = nums[0];
        int n2 = nums[1];
        int n3 = nums[2];

        List<String> list = new ArrayList<>();
        String v1 = Integer.toBinaryString(n1) + Integer.toBinaryString(n2) + Integer.toBinaryString(n3);
        String v2 = Integer.toBinaryString(n1) + Integer.toBinaryString(n3) + Integer.toBinaryString(n2);
        String v3 = Integer.toBinaryString(n2) + Integer.toBinaryString(n1) + Integer.toBinaryString(n3);
        String v4 = Integer.toBinaryString(n2) + Integer.toBinaryString(n3) + Integer.toBinaryString(n1);
        String v5 = Integer.toBinaryString(n3) + Integer.toBinaryString(n1) + Integer.toBinaryString(n2);
        String v6 = Integer.toBinaryString(n3) + Integer.toBinaryString(n2) + Integer.toBinaryString(n1);
        list.add(v1);
        list.add(v2);
        list.add(v3);
        list.add(v4);
        list.add(v5);
        list.add(v6);
        
        int res = Integer.MIN_VALUE;
        for(int i=0; i<6; i++)
        {
            int curr = Integer.parseInt(list.get(i), 2);
            res = Math.max(res, curr);
        }
        return res;
    }
}