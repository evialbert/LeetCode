class Solution {
    public double largestTriangleArea(int[][] points) {
        double result=0;
        for(int i=0;i<points.length;i++){
            for(int j=1;j<points.length;j++){
                for(int k=2;k<points.length;k++){
                    if(i!=j && i!=k && j!=k){
                        double temp = Math.abs(points[i][0]*points[j][1]+points[j][0]*points[k][1]+points[k][0]*points[i][1]-
                                     points[i][0]*points[k][1]-points[j][0]*points[i][1]-points[k][0]*points[j][1])/2.0;
                        if(temp>result){
                            result = temp;
                        }
                    }
                }
            }
        }
        return result;
    }

}