class Solution 
{
public:
    int distMoney(int money, int children) 
    {
        if(money < children) return -1; //when money is lesser than children
        int ans=0;

        //Starts with giving 8 dollars to 1 child         
        for(int n=1; n<=children; n++)
        {
            int rem = money - n*8; //remaining money
            if(rem < children-n) continue; //when remaining money is lesser than remaining children
            if(rem > 0 && (children-n)==0) continue; //when money is left but no children is available
            if(rem==4 && (children-n)==1) continue; //when remaining money is 4 and remaining children is 1
            if(rem==0 && (children-n)>0) continue; //when no money is left but children are left
            else ans = n; //we can easily distribute 8 dollars to n children
        }
        return ans;
    }
};