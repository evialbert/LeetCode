class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        // For Triangle if coordinates are (x1,y1),(x2,y2),(x3,y3) then:
        // Area = (1/2) | x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2) |
        // so area must be zero for collinear of 3 points
        // so no need to take mod and div by 2 for this;

        int n=coordinates.size();
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];

        int area,x3,y3;
        for(int i=2;i<n;i++)
        {
            x3=coordinates[i][0];
            y3=coordinates[i][1];
            area= x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
            if(area)return false;
        }

        return true;

    }
};