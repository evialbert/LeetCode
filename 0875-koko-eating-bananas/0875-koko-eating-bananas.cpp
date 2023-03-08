class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long int  low=1,high=piles[piles.size()-1];
        while(low<=high){
        long long int k=low+(high-low)/2;
        long long int hr=0;
            for(int i=0;i<piles.size();i++){
                hr+=ceil(1.0*piles[i]/k);
            }
            if(hr>h){
                low=k+1;
            }
            else{
                high=k-1;
            }
        }
        return low;
    }
    };