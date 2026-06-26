class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
       vector<int>mark(n,0);
        int act=0;
      for(int i=0;i<lights.size();i++){
          if(lights[i]>0){
              act=max(act,lights[i]+1);
              mark[i]=1;
              act--;
          }
          else if(act>0){
              mark[i]=1;
              act--;
          }
          else continue;
      }
        act=0;
        for(int i=n-1;i>=0;i--){
            if(lights[i]>0){
                act=max(act,lights[i]+1);
                mark[i]=1;
                act--;
            }
            else if(act>0){
                mark[i]=1;
                act--;
            }
            else continue;
        }
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(mark[i]==0) idx.push_back(i);
        }
        if(idx.size()==0) return 0;
        int k=1;
        int cnt=1;
        for(int i=1;i<idx.size();i++){
            if(idx[i]-idx[i-1]==1 && k<3){
                k++;
            }
            else{
                k=1;
                cnt++;
            }
        }
        return cnt;
    }
};