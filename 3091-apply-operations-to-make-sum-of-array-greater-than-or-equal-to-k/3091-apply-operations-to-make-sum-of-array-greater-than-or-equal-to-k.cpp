class Solution {
public:
    int minOperations(int k) {
        int c=1;  int min=INT_MAX; int t=0;
     for(int i=0; i<k; i++){
         int s=0;
         if((k-c)%c==0){
            s=t+(k-c)/c;
          }
         else{
          s=t+(k-c)/c +1;  
          }
         if(s<min){
            min=s;
          }
        t++;  c++;
     }   
     return min; 
    }
};