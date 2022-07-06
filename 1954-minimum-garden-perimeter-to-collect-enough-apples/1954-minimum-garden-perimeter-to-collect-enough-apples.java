class Solution {
    public long minimumPerimeter(long neededApples) {
        return Math.abs((long)Math.ceil(Math.cbrt(-1.0 * neededApples / (2 * 4) + Math.pow(Math.pow(-1.0 * neededApples / (2 * 4), 2) - 1.0/1728.0, 0.5)) + Math.cbrt(-1.0 * neededApples / (2 * 4) - Math.pow(Math.pow(-1.0 * neededApples / (2 * 4), 2) - 1.0/1728.0, 0.5)) - 0.5)) * 8;
    }
}