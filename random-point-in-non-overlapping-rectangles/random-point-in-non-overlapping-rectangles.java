class Solution {
    Random random;
    TreeMap<Integer,int[]> map;
    int areaSum = 0;
    public Solution(int[][] rects) {
        random = new Random();
        map = new TreeMap<>();
        
        for(int i = 0; i < rects.length; i++){
            int[] rectangleCoordinates = rects[i];
            int length = rectangleCoordinates[2] - rectangleCoordinates[0] + 1;
            int breadth = rectangleCoordinates[3] - rectangleCoordinates[1] + 1;
            
            areaSum += length * breadth;
            
            map.put(areaSum,rectangleCoordinates);
        }
    }
    
    public int[] pick() {
        //random.nextInt gives a int in the range of 0 to areaSum and ceilingKey returns a key greater than or equal to the argument passed
        //to it.
        int key = map.ceilingKey(random.nextInt(areaSum) + 1);
        int[] rectangle = map.get(key);
        
        int length = rectangle[2] - rectangle[0] + 1;
        int breadth = rectangle[3] - rectangle[1] + 1;
        
        //length denotes the no of x coordinates we can have.
        //breadth denotes the no of y coordinates we can have
        
        //random.nextInt gives a random value from x1 - x2-1 which we can add to the current x and we can have a valid x .
        //random.nextInt gives a random value from y1 - y2-1 which we can add to the current y and we can have a valid y .
        
        int x = rectangle[0] + random.nextInt(length);
        int y = rectangle[1] + random.nextInt(breadth);
        
        return new int[]{x,y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */