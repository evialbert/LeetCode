class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        int[] result = new int[3];
        for(int j=0;j<triplets.length;j++)
        {
            int[] present = triplets[j];
            if(present[0]<=target[0] && present[1]<=target[1] && present[2]<=target[2])
            {
                result[0] = Math.max(result[0],present[0]);
                result[1] = Math.max(result[1],present[1]);
                result[2] = Math.max(result[2],present[2]);

            }
        }
        return Arrays.equals(target,result);
    }
}