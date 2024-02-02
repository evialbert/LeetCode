class Solution {
public:

    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int totalA=0,totalB=0;
        set<int> stB;
        for(auto a : A)
        {
            totalA+=a;
        }
        for(auto b : B)
        {
            totalB+=b;
            stB.insert(b);
        }
   
      int delta  = (totalB-totalA)/2;

      for(auto a : A)
      {
          if(stB.find(a+delta)!=stB.end())
          {
              ans.push_back(a);
              ans.push_back(a+delta);
              return ans;
          }
      }
 
     return {};
     
    }
};