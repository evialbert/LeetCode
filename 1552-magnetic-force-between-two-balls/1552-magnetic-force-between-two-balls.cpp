class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size(), s=1, e=(position[n-1]-position[0])/(m-1);
        int ans;
        while(s<=e){
            int p=0;
            int mid=(s+e)/2;
            int b=1;
            for(int i=1; i<n ; i++){
                if(b<m){
                    if(position[i]-position[p]>=mid){
                        p=i;
                        b++;
                    }
                }
                else{
                    break;
                }
            }
            if(b==m){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};