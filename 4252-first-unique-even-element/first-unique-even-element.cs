public class Solution {
    public int FirstUniqueEven(int[] nums) {
        Dictionary<int, int> set = new();

        foreach(int x in nums){
            if(x%2 == 0){
                if(set.ContainsKey(x)){
                    set[x]+= 1;
                }
                else{
                    set[x] = 1;
                }
            }
        }

        foreach(int x in nums){
            if(x%2 ==0 && set[x] == 1){
                return x;
            }
        }

        return -1;
    }
}