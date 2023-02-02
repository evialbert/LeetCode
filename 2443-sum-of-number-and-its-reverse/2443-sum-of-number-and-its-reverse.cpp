class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        for(int i =num/2;i<=num;i++)
        {
            int mid = i;
            string s = to_string(mid);
            reverse(s.begin(),s.end());
            int n = stoi(s);
            if((i+n)==num)
            {
                //cout<<i<<" ";
                return true;
            }
                
        }
        return false;
        
    }
};