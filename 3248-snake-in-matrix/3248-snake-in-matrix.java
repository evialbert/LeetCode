class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int x = 0;
        int y = 0;
        for (String s : commands) {
            if (s.equals("RIGHT")) {
                y++;
            } 
            else if (s.equals("LEFT")) {
                y--;
            } 
            else if (s.equals("DOWN")) {
                x++;
            } 
            else if (s.equals("UP")) {
                x--;
            }
        }
        return x * n + y;
    }
}