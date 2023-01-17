class Solution {
public:
    int uniquePaths(int a, int b) {
         vector<int>prev(b,0);
        for(int i=0;i<a;i++){
            vector<int> curr(b,0);
            for(int j=0;j<b;j++){
                if( i==0 && j==0 )  curr[j] = 1;
                else{
                    int down=0,right=0;
                    if(i>0) {
                        down = prev[j];
                    }
                  if(j>0){
                        right = curr[j-1];
                  } 
                 curr[j] = down+right;
                }
            }
            prev=curr;
        }
        return prev[b-1];
    }
};