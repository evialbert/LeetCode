class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
     double maxi=-1.0;
     
     int area=0;
     for(auto i: dimensions){
         double d=sqrt(i[0]*i[0]+i[1]*i[1]);
         if(d>maxi){
             maxi=d;
          
             area=i[0]*i[1];
         }else if(d==maxi){
             area=max(area,i[0]*i[1]);
         }
     }
     
     return area;
        
    }
};