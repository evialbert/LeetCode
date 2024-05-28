public class Solution {
    public int DuplicateNumbersXOR(int[] nums) {
        var set = new HashSet<int>();
        int res = 0;
        foreach(int num in nums)
        {
            if(set.Add(num) == false)
                res ^= num;
        }
        return res;
    }
}