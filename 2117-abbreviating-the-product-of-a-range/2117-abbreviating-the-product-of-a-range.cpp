class Solution {
public:

    string abbreviateProduct(int left, int right) {
    
        string Ans = "1",Prefix ="1";
        int count = 0;
        for(int i=left;i<=right;i++)
        {
            Ans = to_string(i*stol(Ans));
            while(Ans.back()=='0') Ans.pop_back() , count++;
            if(Ans.size()>12)
            Ans =Ans.substr(Ans.size()-12); 
        }
        
        long double SumLog= 0;
        for(int i=left;i<=right;i++)
        SumLog += log10(i);
        string P =to_string(floor(pow(10,4.0+(SumLog-long(SumLog)))));
        
        if(Ans.size()>10)
        Ans = (P.size()>5?P.substr(0,5):P) +"..." + Ans.substr(Ans.size()-5);
        
        return Ans+"e"+to_string(count);
    }
};