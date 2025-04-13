class Solution {
    public int findClosest(int x, int y, int z) {
        int d1 = x > z ? x - z : z - x;
        int d2 = y > z ? y - z : z - y;

        if(d1 < d2) return 1;
        else if(d1 > d2) return 2;
        return 0;
    }
}