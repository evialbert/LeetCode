//Time complexity:O(n)
//Space complexity:O(1)

class Solution {
public:

int solve(vector<int>& colors , int low, int high){
    if(low>high) return -1;
    int ans=0;
    if(colors[low]==colors[high]){
        ans=max(solve(colors,low+1,high) ,solve(colors,low,high-1));
    }
    else return abs(low-high);
    return ans;
}

    int maxDistance(vector<int>& colors) {
        int low=0;
        int n=colors.size();
        int high=n-1,ans=0;

        if(colors[low]==colors[high]){

            while(low<high && colors[low]==colors[high]){
                low++;
            }
            ans=abs(high-low);
            low=0;
            high=n-1;
            while(low<high && colors[low]==colors[high]){
                high--;
            }
            return max(ans,abs(high-low));
        }
        return abs(high-low);
    }
};