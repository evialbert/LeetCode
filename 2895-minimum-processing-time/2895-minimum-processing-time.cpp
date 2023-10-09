class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
       sort(processorTime.begin(),processorTime.end());
       sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
       int ans=INT_MIN; 
       for(int i=0;i<processorTime.size();i++){
           int j=i*4;
           int temp=i*4+4;
           int maxi=INT_MIN;
       while(j<temp){
           maxi=max(maxi,(processorTime[i]+tasks[j]));
           j++;
       }
           ans=max(ans,maxi);
       }
        return ans;
    }
};