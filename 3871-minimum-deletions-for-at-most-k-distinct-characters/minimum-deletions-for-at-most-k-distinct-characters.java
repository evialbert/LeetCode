class Solution {
    public int minDeletion(String s, int k) {
        var freq = s.chars()
            .mapToObj(c -> (char) c)
            .collect(
                Collectors.groupingBy(
                    Function.identity(),
                    Collectors.counting()
                )
            );
        var d = freq.entrySet().size() - k;
        var count = freq.entrySet()
            .stream()
            .map(e -> e.getValue().intValue())
            .sorted()
            .toList();

        return d <= 0 ? 0 : count.stream()
            .limit(d)
            .reduce(Integer::sum)
            .orElse(0)
            ;
    }
}