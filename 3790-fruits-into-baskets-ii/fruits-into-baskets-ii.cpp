class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int c=0;
        for(auto &i:fruits){
            bool f=false;
            for(auto &j:baskets){
                if(i<=j && j!=-1){
                    j=-1;
                    f=true;
                    break;
                }
            }
            if(!f){
                c++;
            }
        }
        return c;
    }
};