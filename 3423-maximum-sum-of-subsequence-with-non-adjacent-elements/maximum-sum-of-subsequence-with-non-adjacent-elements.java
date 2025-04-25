class Solution {
    class CustomNode {
        CustomNode left, right;
        int start, end;
        // containStart means the subsequence - [start, end] contains the element on index 'start', but not contains the element on index 'end'
        // containEnd means the subsequence - [start, end] don't contain the element on index 'start', but contains the element on index 'end'
        // notContain means the subsequence - [start, end] don't contain both the elements on index 'start' and 'end'
        // containBoth means the subsequence - [start, end] contains both the elements on index 'start' and 'end'
        long containStart, containEnd, notContain, containBoth;

        CustomNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.containStart = 0;
            this.containEnd = 0;
            this.notContain = 0;
            this.containBoth = 0;
        }

        public void update(int index, int val) {
            if (index > end || index < start) return;
            if (start == end) {
                containStart = 0;
                containEnd = 0;
                notContain = 0;
                containBoth = val;
                return;
            }
            int mid = start + (end - start) / 2;
            if (left == null) {
                left = new CustomNode(start, mid);
                right = new CustomNode(mid + 1, end);
            }
            left.update(index, val);
            right.update(index, val);
            containStart = getMaxContainStart(left, right);
            containEnd = getMaxContainEnd(left, right);
            notContain = getMaxNotContain(left, right);
            containBoth = getMaxContainBoth(left, right);
        }

        public long query() {
            long ret = 0;
            ret = Math.max(ret, containStart);
            ret = Math.max(ret, containEnd);
            ret = Math.max(ret, containBoth);
            ret = Math.max(ret, notContain);
            return ret;
        }

        private long getMaxContainBoth(CustomNode left, CustomNode right) {
            long ret = Long.MIN_VALUE;
            ret = Math.max(ret, left.containStart + right.containEnd);
            ret = Math.max(ret, left.containStart + right.containBoth);
            ret = Math.max(ret, left.containBoth + right.containEnd);
            return ret;
        }

        private long getMaxNotContain(CustomNode left, CustomNode right) {
            long ret = Long.MIN_VALUE;
            ret = Math.max(ret, left.containEnd + right.notContain);
            ret = Math.max(ret, left.notContain + right.notContain);
            ret = Math.max(ret, left.notContain + right.containStart);
            return ret;
        }

        private long getMaxContainEnd(CustomNode left, CustomNode right) {
            long ret = Long.MIN_VALUE;
            ret = Math.max(ret, left.containEnd + right.containEnd);
            ret = Math.max(ret, left.notContain + right.containEnd);
            ret = Math.max(ret, left.notContain + right.containBoth);
            return ret;
        }

        private long getMaxContainStart(CustomNode left, CustomNode right) {
            long ret = Long.MIN_VALUE;
            ret = Math.max(ret, left.containStart + right.containStart);
            ret = Math.max(ret, left.containStart + right.notContain);
            ret = Math.max(ret, left.containBoth + right.notContain);
            return ret;
        }
    }
    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        int n = nums.length;
        CustomNode root = new CustomNode(0, n - 1);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            root.update(i, num);
        }
        long ret = 0;
        for (int i = 0; i < queries.length; i++) {
            int[] query = queries[i];
            root.update(query[0], query[1]);
            ret += root.query();
        }
        return (int) (ret % ((int) 1e9 + 7));
    }
}