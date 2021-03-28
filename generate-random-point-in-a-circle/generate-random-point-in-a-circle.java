class Solution {
    
    double radius;
    double x_center;
    double y_center;
    Random random;

    public Solution(double radius, double x_center, double y_center) {
        
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
        random = new Random ();
    }
    
    public double[] randPoint() {
        
        double x = getCoordinate (x_center);
        double y = getCoordinate (y_center);
        
        while (getDistance (x, y) >= radius * radius) {
            x = getCoordinate (x_center);
            y = getCoordinate (y_center);
        }
        
        return new double[] {x, y};
    }
    
    private double getDistance (double x, double y) {
        
        return (x_center - x) * (x_center - x) + (y_center - y) * (y_center - y);
    }
    
    private double getCoordinate (double center) {
        
        return center - radius + Math.random () * 2 * radius;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */