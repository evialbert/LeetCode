class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> output = new ArrayList();
        if (finalSum % 2 != 0) return output;
        
        long i = 2;
        while (i <= finalSum) {
            output.add(i);
            finalSum -= i;
            i += 2;
        }
        if(finalSum != 0) output.set(output.size() - 1, output.get(output.size() - 1) + finalSum);
        return output;
    }
}