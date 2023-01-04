class Solution {
public:
    
    int findPoint(vector<int> &potions,long long success,int current){
        int low = 0;
        int high = potions.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if((long long)potions[mid]*current>=success)
                high=mid-1;
            else
                low=mid+1;
        }
        return potions.size()-low;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            spells[i]=findPoint(potions,success,spells[i]);
        }
        return spells;
    }
};
