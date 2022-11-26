class Solution {
public:
    bool liesInside(int cx , int cy , int r , int x , int y){
        int d = (cx-x)*(cx-x) + (cy-y)*(cy-y) ;
        if(d <= r*r) return true ;
        return false ;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        int latticePoints = 0 ;
        //maximum point covered can be 200 , assumed x = 100 , y = 100 then radius = 100 ;
        for(int x = 0 ; x <= 200 ; ++x ){
            for(int y = 0 ; y <= 200 ; ++y){
                
                for(auto &circle : circles){
                    int cx = circle[0] , cy = circle[1] , r = circle[2] ;
                    if(liesInside(cx,cy,r,x,y)){
                        ++latticePoints ;
                        break ;
                    }
                }
            }
        }
        return latticePoints ;
    }
};