class Solution {
int[] twoThree = new int[]{2,3};
int[] oneThree = new int[]{1,3};
int[] oneTwo = new int[]{1,2};
public int minSideJumps(int[] obstacles) 
{
    int lane = 2, n = obstacles.length;
    Integer[][] memo = new Integer[n][4];
    return dfs(lane, obstacles, 0, memo);
}

int dfs(int lane, int[] obstacles, int index, Integer[][] memo)
{
    if(index == obstacles.length-1)
    {
        return 0;
    }
    
    if(memo[index][lane] != null)
    {
        return memo[index][lane];
    }
    
    if(obstacles[index] == lane)
    {
        return Integer.MAX_VALUE;
    }
    
    int min = Integer.MAX_VALUE;
    if(obstacles[index+1] == lane)
    {
        int[] lanes = getOtherLanes(lane);
        min = 1 + Math.min(dfs(lanes[0], obstacles, index, memo), dfs(lanes[1], obstacles, index, 
                                                                      memo));
    }
    else
    {
        min = dfs(lane, obstacles, index+1, memo);
    }
    
    return memo[index][lane] = min;
}

int[] getOtherLanes(int currentLane)
{
    if(currentLane == 1)
    {
        return twoThree;
    }
    else if(currentLane == 2)
    {
        return oneThree;
    }
    else
    {
        return oneTwo;
    }
}               
}