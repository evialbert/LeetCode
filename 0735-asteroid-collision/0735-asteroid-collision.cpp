class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> res; 
        stack<int> s;
        
        for(auto it: asteroids)
        {
            // If the values are positive then we will keep on pushing it onto the stack, no problem :) cause they will never collide 
            if(it > 0)
            {
                s.push(it);
            }
            
            else
            {
                // If the stack is empty && Top most element is +ve ( beacuse -ve first and then +ve will never collide ) && s.top < abs(element) as per given condition, then we pop off the element 
                while(!s.empty() && s.top() > 0 && s.top() < abs(it))
                {
                    s.pop();
                }
                // Incase we find both elements to be same (abs value) then we pop it off, because they will collide  
                if(!s.empty() && s.top() == abs(it))
                {
                    s.pop();
                }
                
                //Lets say, if there was only one asteroid with a negative value, then we push it onto our stack and make it a part of our result OR all the values of the asteroid are negative 
                else if(s.empty() || s.top()<0)
                {
                    s.push(it);
                }
            }
        }
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};