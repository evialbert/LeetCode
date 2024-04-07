class Solution {
public:
    bool checkValidString(string s) 
    {
        int leftmin=0, leftmax=0;
        for(auto i:s)
        {
            if(i=='(')
            {
                leftmin++;
                leftmax++;
            }
            else if(i=='*')
            {
                leftmin--;
                leftmax++;
            }
            else
            {
                leftmin--;
                leftmax--;
            }
            if(leftmax<0)
                return false;
            if(leftmin<0)
                leftmin=0;
        }
        return (leftmin==0)? true : false;
    }
};