class Solution {
public:
    int countCollisions(string directions) {
          int collisions = 0, i = 0, R = 0;
          // skipping the left car's from the starting, because
          // they wont contribute to the answer
        
        while(directions[i] == 'L') i++;
          
        for(; i<directions.size(); i++){
               if(directions[i] == 'R') R++;
               else {
                   if(directions[i] == 'L'){
                       collisions += R + 1;
                   }
                   else collisions += R;
                   R = 0;
               }
                   
           }
        return collisions;
    }
};