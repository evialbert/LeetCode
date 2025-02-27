public class Solution {
    public int maxDistance(int side, int[][] points, int k) {
        int n = points.length;
        long[] linearSeq = new long[n];
        for (int i = 0; i < n; i++) {
            linearSeq[i] = map(points[i], side);
        }
        Arrays.sort(linearSeq);
        linearSeq = extendSeq(linearSeq, side);

        int st = 0, end = 2 * side, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(linearSeq, side, k, mid)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    public long map(int[] points, int side) {
        int x = points[0];
        int y = points[1];
        if (y == 0) {
            return x;
        }
        if (x == side) {
            return side + y;
        }
        if (y == side) {
            return 3L * side - x;
        }
        return 4L * side - y;
    }

    public long[] extendSeq(long[] seq, int side) {
        int n = seq.length;
        long[] newSeq = new long[2 * n];
        for (int i = 0; i < n; i++) {
            newSeq[i] = seq[i];
            newSeq[n + i] = seq[i] + (4L * side);
        }
        return newSeq;
    }

    public boolean isValid(long[] linearSeq, int side, int k, long p) {
        int n = linearSeq.length / 2;
        for (int i = 0; i < n; i++) {
            long initPos = linearSeq[i];
            int idx = i;
            int count = 1;
            for (int j = 1; j < k; j++) {
                long minDist = initPos + p;
                int nxtIdx = binarySearch(linearSeq, idx + 1, i + n, minDist);
                if (nxtIdx == i + n) {
                    count = -1;
                    break;
                }
                idx = nxtIdx;
                initPos = linearSeq[idx];
                count++;
            }
            if (count == k && (linearSeq[i] + 4L * side - initPos) >= p) {
                return true;
            }
        }
        return false;
    }

    public int binarySearch(long[] seq, int st, int end, long tar) {
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (seq[mid] >= tar) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
}