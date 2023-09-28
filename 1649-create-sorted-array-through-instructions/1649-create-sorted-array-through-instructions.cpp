class Solution {
public:
   vector<int>seg ; 
    int mod = 1e9+7 ;
    int query(int ind ,int low, int high , int l ,int r )
    {
        if(r<low || high<l)
            return 0 ; 
        if(l<=low && high<=r)
            return seg[ind]; 
        
        int mid= (low+high)/2 ;
        
        int left = query(2*ind+1 , low ,mid , l ,r ) ;
        int right = query(2*ind+2 , mid+1, high , l ,r ) ; 
        
        return left+right ; 
    }
    
    void update(int ind  , int low, int high , int val )
    {
        if(low==high)
        {
            seg[ind]++ ; 
            return  ; 
        }
        int mid  =(low+high)/2; 
        
        if(val<=mid)
            update(2*ind+1 , low, mid, val ) ;
        else
            update(2*ind+2 ,mid+1, high ,val ); 
        
        
        seg[ind]  = seg[2*ind+1]+seg[2*ind+2]; 
    }
    

    int createSortedArray(vector<int>& in) {
        
        seg.resize(400001) ;
        long long  ans =0 ; 
        int n = in.size() ; 
        for(int i = 0 ;i<n ;i++ )
        {
            int mini = query(0 ,0 , 100001 , 0 , in[i]-1 ); 
            int maxi = query(0 ,0 , 100001 , in[i]+1 , 100001 ) ;
            
            ans=(ans+min(mini , maxi))%mod ; 
            
            update(0 , 0, 100001 , in[i]) ; 
        }
        return ans ;
    }
};