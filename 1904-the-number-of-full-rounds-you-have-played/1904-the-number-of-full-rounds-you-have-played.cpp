class Solution {
public:
    int numberOfRounds(string l, string lo) {
        int a=stoi(l.substr(0,2));
        int b=stoi(l.substr(3,2));
        int c=stoi(lo.substr(0,2));
        int d=stoi(lo.substr(3,2));
        if(a==c && b<d)
        { 
            //If hours are same  and login<logout same we need to find intervals in between
            if(b>0 && b%15!=0)
            {//Make b to start of next interval if this interval is already disturbed
                b=b+(15-b%15);
            }
            
            return ((d-b)/15)>0?((d-b)/15):0;
        }
        if(b)
        {
            //count intervals beween a& a+1 hrs and store them in b & increase a to a+1
            a++;
             b=(60-b)/15;
        }
       
        d=d/15;//count intervals after c hrs and store stem in d
        
        int a1=0;
        int a2=0;
        if(lo<l)
        {
            return (((24-a)+c)*4)+b+d;//simply find difference in number of hrs each hr contains 4 full intervals & add b and d
        }
        else if(lo>l)
        {
            
            return (c-a)*4+b+d;////simply find difference in number of hrs each hr contains 4 full intervals & add b and d
        }
        else 
        {
            return 0;
        }
    }
};