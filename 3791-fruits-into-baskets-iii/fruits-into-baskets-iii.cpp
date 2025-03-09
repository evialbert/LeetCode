class Solution {
public:
    vector<int>segTree;
    void constructTree(vector<int>& baskets,int st,int ed,int nd){
        if(st==ed){
            segTree[nd]=baskets[st];
            return;
        }
        int mid=(st+ed)/2;

        constructTree(baskets,st,mid,2*nd);
        constructTree(baskets,mid+1,ed,2*nd+1);

        segTree[nd]=max(segTree[2*nd],segTree[2*nd+1]);
    }

    int search(int n,int st,int ed,int k){
        if(segTree[n]<k) return -1;
        if(st==ed){
            segTree[n]=-1;
            return st;
        }
        int mid=(st+ed)/2;
        int pos=0;
        if(segTree[2*n]>=k){
           pos= search(2*n,st,mid,k);
        }
        else{
            pos=search(2*n+1,mid+1,ed,k);
        }
        segTree[n]=max(segTree[2*n],segTree[2*n+1]);
        return pos;
    }


    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        segTree.assign(4*n,0);
        constructTree(baskets,0,n-1,1);

        int unplaced=0;
        for(int i=0;i<n;i++){
            if(search(1,0,n-1,fruits[i])==-1){
                unplaced++;
            }
        }
        return unplaced;

    }
};