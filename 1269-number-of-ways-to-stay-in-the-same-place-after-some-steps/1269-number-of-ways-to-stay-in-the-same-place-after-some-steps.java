class Solution {

    int arrLen, steps;
    long[][] memo;

    public int numWays(int steps, int arrLen) {
        this.steps = steps; 
        this.arrLen = arrLen-1;

        memo = new long[Math.min(arrLen, 501)][steps+1];

        for(long[] m: memo) Arrays.fill(m, -1);

        return (int) takeStep(0, steps);
    }

    public long takeStep(int index, int currStep){
        if(currStep == 0 || currStep < index)
            if(index == 0) return 1;
            else return 0;

        if(memo[index][currStep] != -1) return memo[index][currStep];

        long sum = 0;
        int nextStep = currStep - 1;

        sum += takeStep(index, nextStep);
        if(index != 0) sum += takeStep(index - 1, nextStep);
        if(index != arrLen) sum += takeStep(index + 1, nextStep);

        return memo[index][currStep] = sum%1000_000_007;
    }
}