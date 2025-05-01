class Solution {
    public int minimumPairRemoval(int[] nums) {
        int os = 0;
        while (true) {
            boolean sSted = true;
            for (int d = 1; d < nums.length; d++) {
                if (nums[d] < nums[d - 1]) 
                {
                    sSted = false;
                    break;
                }
            }
            if (sSted) break;
            int mim = Integer.MAX_VALUE, ix = -1;
            for (int x = 0; x< nums.length - 1; x++) 
            {
                int um = nums[x] + nums[x + 1];
                if (um < mim) {
                    mim = um;
                    ix = x;
                }
            }
            int[] nems = new int[nums.length - 1];
            for (int b = 0, z = 0; b< nums.length; b++) {
                if (b == ix) 
                {
                    nems[z++] = nums[b] + nums[b + 1];
                    b++;
                } else {
                    nems[z++] = nums[b];
                }
            }
            nums = nems;
            os++;
        }
        return os;
    }

    public static int[] parseInput(String ict) {
        ict = ict.replaceAll("[\\[\\]\\s]", "");
        String[] pts = ict.split(",");
        int[] nums = new int[pts.length];
        for (int s = 0; s < pts.length; s++) {
            nums[s] = Integer.parseInt(pts[s]);
        }
        return nums;
    
    }
}