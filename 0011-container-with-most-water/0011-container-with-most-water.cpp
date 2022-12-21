class Solution {
public:
    int maxArea(vector<int>& height) {
        long long int i=0, j=height.size()-1, maxi=INT_MIN;
        while(i<j){
            //cout<<(j-i)*(min(height[i], height[j]))<<endl;
            maxi=max(maxi, (j-i)*(min(height[i], height[j])));
            if(height[i]<=height[j]){
                i++;
            }
            else{j--;}
        }
        return maxi;
    }
};