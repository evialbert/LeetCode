class Solution {
    public int brokenCalc(int X, int Y) {
        if(X==Y)
        {
            return 0;
        }
        if(X>Y)
        {
            return X-Y;
        }
        else
        {
            if(Y%2==1)
            {
                return 1+brokenCalc(X,Y+1);
            }
            else
            {
                return 1+brokenCalc(X,Y/2);
            }
        }
    }
}