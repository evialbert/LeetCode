class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        unordered_map<int,int> map,map1;
        int ans=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)arr[i]--;
        for(int i=0;i<n;i++)
        {
            if(!map1.count(arr[i]-1) && !map1.count(arr[i]+1))
            {
                map[1]++;
                map1[arr[i]]=1;
            }
            else if(map1.count(arr[i]-1) && map1.count(arr[i]+1))
            {
                int x=map1[arr[i]-1],y=map1[arr[i]+1];
                map1[arr[i]-x]=x+y+1;
                map1[arr[i]+y]=x+y+1;

                map[x+y+1]++;
                map[x]--;
                map[y]--;
            }
            else if(map1.count(arr[i]-1))
            {
                int x=map1[arr[i]-1];
                map1[arr[i]]=x+1;
                map1[arr[i]-x]=x+1;
                map[x+1]++;
                map[x]--;
            }
            else if(map1.count(arr[i]+1))
            {
                int x=map1[arr[i]+1];
                map1[arr[i]]=x+1;
                map1[arr[i]+x]=x+1;
                map[x]--;
                map[x+1]++;
            }
            if(map[m]>0)ans=i+1;
        }
        return ans;
    }
};