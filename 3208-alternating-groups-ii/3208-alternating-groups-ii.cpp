class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int n=colors.size();
       int ans=0,cnt=1; // cnt for prefix sum of alternating colors
for(int i=1;i<n+k-1;i++){ 
if(colors[i%n]!=colors[(i-1)%n]) cnt++;
else cnt=1;
if(cnt>=k) ans++; // alternating colors>k includes our ans
}       
return ans;
    }
};