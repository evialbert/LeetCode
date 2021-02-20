public class Solution {
    public void combinationSum(List<List<Integer> > result, List<Integer> array, int k, int start, int sum) {

        if (sum < 0) return;
        if (k == 0) {
            if (sum == 0) result.add(new ArrayList<Integer> (array));
            return;
        }

        int i, size = array.size();

        for (i = start; i < 10; i++) {
            array.add(i);
            combinationSum(result, array, k - 1, i + 1, sum - i);
            array.remove(size);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {

        List<List<Integer> > result = new ArrayList<List<Integer> > ();
        List<Integer> array = new ArrayList<Integer> ();

        combinationSum(result, array, k, 1, n);

        return result;
    }
}