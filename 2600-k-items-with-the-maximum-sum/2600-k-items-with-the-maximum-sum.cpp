class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans=0;
        for(int i=0;i<numOnes;i++){
            if(k>0){
                ans+=1;
                k--;
            }
        }
        for(int i=0;i<numZeros;i++){
            if(k>0){
                ans+=0;
                k--;
            }
        }
        for(int i=0;i<numNegOnes;i++){
            if(k>0){
                ans-=1;
                k--;
            }
        }
        return ans;
    }
};