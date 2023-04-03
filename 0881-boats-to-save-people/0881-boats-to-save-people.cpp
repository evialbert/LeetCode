class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int n = people.size();
        int low = 0;
        int high = n-1;
        sort(people.begin(),people.end());
        while(low <= high){
            
            if(people[low] + people[high] <= limit){
                low++;
                high--;
            }
            else if(people[low] + people[high] > limit){
                high--;
            }
            
            count ++;
        }
        
        return count;
    }
};