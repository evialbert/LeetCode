class Solution {

    private void getAns(int[] firstStart, int[] firstDuration,
                        int[] secondStart, int[] secondDuration,
                        int[] ans) {

        // Earliest finish time of first category
        int minFinish = Integer.MAX_VALUE;

        for(int i = 0; i < firstStart.length; i++) {
            minFinish = Math.min(minFinish,
                                 firstStart[i] + firstDuration[i]);
        }

        // Try every ride of second category
        for(int i = 0; i < secondStart.length; i++) {

            int finishTime =
                Math.max(secondStart[i], minFinish)
                + secondDuration[i];

            ans[0] = Math.min(ans[0], finishTime);
        }
    }

    public int earliestFinishTime(int[] landStartTime,
                                  int[] landDuration,
                                  int[] waterStartTime,
                                  int[] waterDuration) {

        int[] ans = {Integer.MAX_VALUE};

        getAns(landStartTime, landDuration,
               waterStartTime, waterDuration, ans);

        getAns(waterStartTime, waterDuration,
               landStartTime, landDuration, ans);

        return ans[0];
    }
}