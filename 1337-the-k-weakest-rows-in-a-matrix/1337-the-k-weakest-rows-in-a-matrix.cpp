class Solution {
public:
     int lastOcc(vector<int>&a){     
        int lo=0,hi=a.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(a[mid]==1){
                ans=mid;
                lo=mid+1;
            }else if(a[mid]<1){
                hi=mid-1;
            }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        vector<pair<int, int>> vect;
        
        int m = mat.size();
        for(int i=0; i<m; i++)
        {
            int cnt=lastOcc(mat[i])+1;            
            vect.push_back({cnt, i});
        }
        
        sort(vect.begin(), vect.end());
        
        for(int i=0; i<k; i++)
        {
            ans.push_back( vect[i].second);
        }
        return ans;
    }
};