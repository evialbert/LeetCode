class Solution {
public:
    bool reorderedPowerOf2(int n) {
       
        string s = to_string(n);
        map<char,int> mpp;    // stores original
       
            for(auto& it:s) mpp[it]++;

        for(int i=0;i<30;i++){      // max comparision till 30 bits
            map<char,int> fnk;    // new hashmap for new unique values
            int  x = 1;        
            x = x << i;    // left shift to get multiple power of 2
            string ss = to_string(x);   
            for(auto& it:ss) fnk[it]++; 
            if(fnk==mpp) return true;  //hashmap removes the need to rearrange the elements and check
        }
        return false;
        
    }
};