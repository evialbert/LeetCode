class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> counts(1001,0);
        int maxRabbits=0;
        for(int num:answers){
            if(counts[num+1]==0){
                counts[num+1]=1;
                maxRabbits+=num+1;
            }
            else{
                if(counts[num+1] == num+1){
                    counts[num+1]=1;
                    maxRabbits+=num+1;
                }
                else{
                    counts[num+1]++;
                }
            }
        }
        return maxRabbits;
    }
};