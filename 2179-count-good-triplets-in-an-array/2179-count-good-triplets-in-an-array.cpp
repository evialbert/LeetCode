class Solution {
public:

    void update(int ind, int l,int r,int val,vector<int> &tree,int par){
        if(l>val || r<val) return;
        if(l==r){
            if(par==0) tree[ind]++;
            else tree[ind]--;
            return;
        }

        int mid=(l+r)/2;
        update(2*ind,l,mid,val,tree,par); 
        update(2*ind+1,mid+1,r,val,tree,par); 

        tree[ind]=tree[2*ind]+tree[2*ind+1];
    }

    int find(int ind, int l,int r,int val,vector<int> &tree,int par){
        if(l>val and par==0) return 0;
        if(r<val and par==1) return 0;

        if(r<=val and par==0) return tree[ind];
        if(l>=val and par) return tree[ind];

        int mid=(l+r)/2;
        int left=find(2*ind,l,mid,val,tree,par);
        int right=find(2*ind+1,mid+1,r,val,tree,par);

        return left+right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>pos(n);
        for(int i=0;i<n;i++) pos[nums2[i]]=i;
        vector<int>left(4*n+10,0),right(4*n+10,0);
        update(1,0,n-1,pos[nums1[0]],left,0);
        for(int i=2;i<n;i++) update(1,0,n-1,pos[nums1[i]],right,0);

        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans+=1LL*find(1,0,n-1,pos[nums1[i]],left,0)*find(1,0,n-1,pos[nums1[i]],right,1);
            update(1,0,n-1,pos[nums1[i]],left,0);
            update(1,0,n-1,pos[nums1[i+1]],right,1);
        }

        return ans;
    }
};