class Solution {
public:
    double area(double x1, double x2, double y1, double y2){
        double ans=(x2-x1)*(y2-y1);
        return ans;

    }
    double checkAbove(double x1, double x2, double y1, double y2, double mid){
        if(mid<=y2 && mid>=y1)
        return area(x1, x2 , mid, y2);
        else if(mid<=y1)
            return area(x1,x2,y1,y2);
        else
            return 0;
    }

    double checkArea(double mid, vector<vector<int>>& squares){
        double totalAb=0;
        double totalBe=0;
        for(int i=0;i<squares.size();i++){
            int x1= squares[i][0];
            int y1= squares[i][1];
            int l1= squares[i][2];
            int x2= x1+l1;
            int y2= y1+l1;
            totalAb+=checkAbove(x1, x2, y1, y2, mid);
        }
        return totalAb;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total=0;
        int maxy=INT_MIN;
        int miniy=INT_MAX;
        for(int i=0;i<squares.size();i++){
            int x1= squares[i][0];
            int y1= squares[i][1];
            int l1= squares[i][2];
            int x2= x1+l1;
            int y2= y1+l1;
            maxy=max(maxy,y2);
            miniy=min(miniy,y1);
            total+= 1ll*(x2-x1)*(y2-y1);
        }
        double low=miniy, high=maxy;
        double ans=0;
        double mid;
        while(high-low>=0.000001){
            mid=low+(high-low)/2;
            double check= checkArea(mid, squares);
            if(check<=total/2)
                high=mid-0.000001;
            else
                low=mid+0.000001;
        }
        return high;
    }
};