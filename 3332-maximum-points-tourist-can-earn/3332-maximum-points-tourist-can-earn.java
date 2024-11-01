class Solution {
    int days;
    int cities;
    Integer[][]dp;
    int f(int day, int city, int[][] stayScore, int[][] travelScore) {
        if(day == days) return 0;
        if(dp[day][city] != null) return dp[day][city];
        int maxScore = 0;
        for(int desCity = 0; desCity < cities; desCity++) {
            int score = 0;
            if(desCity == city)
                score = stayScore[day][city];
            else 
                score = travelScore[city][desCity];
            maxScore = Math.max(maxScore, score+ f(day+1, desCity, stayScore, travelScore));
        }
        return dp[day][city] = maxScore;
    }
    public int maxScore(int n, int k, int[][] stayScore, int[][] travelScore) {
        days = k;
        cities = n;
        int maxScore = 0;
        dp = new Integer[days+1][cities+1];
        for (int city = 0; city < cities; city++) {
            maxScore = Math.max(maxScore, f(0, city, stayScore, travelScore));
        }
        return maxScore;
    }
}