class Solution {
    public int centeredSubarrays(int[] nums) {
        final int n = nums.length;
        final int[] sumPrefixes = new int[n + 1];
        final Frequencies[] freqPrefixes = Frequencies.arrayOfSize(n + 1);
        for (int i = 0; i < n; ++i) {
            final int ip1 = i + 1;
            sumPrefixes[ip1] = sumPrefixes[i] + nums[i];
            freqPrefixes[ip1].putAll(freqPrefixes[i]);
            freqPrefixes[ip1].increment(nums[i]);
        }
        int centered = 0;
        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < j; ++i) {
                final int sum = sumPrefixes[j] - sumPrefixes[i];
                final int freq = freqPrefixes[j].get(sum) - freqPrefixes[i].get(sum);
                if (freq > 0) {
                    centered++;
                }
            }
        }
        return centered;
    }

    static class Frequencies extends HashMap<Integer, Integer> {

        private static final BiFunction<Integer, Integer, Integer> MERGE = Integer::sum;

        private final int get(final int x) {
            return getOrDefault(x, 0);
        }

        private final void increment(final int x) {
            merge(x, 1, MERGE);
        }

        static Frequencies[] arrayOfSize(final int n) {
            final Frequencies[] out = new Frequencies[n];
            for (int i = 0; i < n; ++i) {
                out[i] = new Frequencies();
            }
            return out;
        }
    }
}