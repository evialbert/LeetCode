class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> res = new HashSet<>();
        for (int i = 1; i < bound; i *= x > 1 ? x : bound + 1)
            for (int j = 1; i + j <= bound; j *= y > 1 ? y : bound + 1)
                res.add(i + j);
        return new ArrayList<>(res);
    }
}