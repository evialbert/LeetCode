class Solution {
public:
    struct Node{

        long long val;
        bool has;
        Node()
        {
            val=0;
            has=false;
        }
        Node(long long v, bool h)
        {
            val=v;
            has=h;
        }
    };
    enum Op {SUM,MAX,MIN,GCD,XOR};
  
    struct segTree
    {
        int n;
        bool isMin=true;
        Op op;
        vector<Node>t;
        segTree(){}
        segTree(int n_,Op op_){
            n=n_;
            op=op_;
            t.assign(4*n+500,Node());
        }

        long long combine_val(long long v1,long long v2)
        {
            switch(op){
                case SUM: return v1+v2;
                case MAX: return max(v1,v2);
                case MIN: return min(v1,v2);
                case XOR: return v1^v2;
                case GCD: return gcd(v1,v2);
            }
            return 0;
        }

        Node merge(Node a,Node b)
        {
            if(!a.has) return b;
            if(!b.has) return a;
            return Node(combine_val(a.val,b.val),true);
        }

        void build(int id,int l,int r)
        {
            if(l==r)
            {
                t[id]=Node(0,false);
                return;
            }
            int mid=(l+r)/2;

            build(2*id,l,mid);
            build(2*id+1,mid+1,r);
            t[id]=merge(t[2*id],t[2*id+1]);
        }

        void update(int id,int l,int r,int pos,int val)
        {

            if(pos<l || pos >r) return;
            if(l==r)
            {
                t[id]=Node(val,true);
                return;
            }

            int mid=(l+r)/2;

            update(2*id,l,mid,pos,val);
            update(2*id+1,mid+1,r,pos,val);
            t[id]=merge(t[2*id],t[2*id+1]);
        }

        Node query(int id,int l,int r,int lq,int rq)
        {
            if(lq>r || l>rq) return Node();

            if(lq<=l && r<=rq) return t[id];

            int mid=(l+r)/2;

            return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));
        }

        int getVal(int l,int r)
        {
            return query(1,0,n-1,l,r).val;
        }
    };
   
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        segTree segMini(n,MIN);
        for(int i=0;i<n;i++) segMini.update(1,0,n-1,i,nums[i]);
        
        segTree segMaxi(n,MAX);
        for(int i=0;i<n;i++) segMaxi.update(1,0,n-1,i,nums[i]);

        priority_queue<pair<int,pair<int,int>>>q;
        set<pair<int,int>>st;

        long long val=segMaxi.getVal(0,n-1)-segMini.getVal(0,n-1);
        q.push({val,{0,n-1}});
        st.insert({0,n-1});

        long long result=0;
        while(!q.empty() && k>0)
        {
            auto [diff,range]=q.top();q.pop();

            int l=range.first;
            int r=range.second;
            result+=diff;
            k--;

            if(l+1<=r && st.find({l+1,r})==st.end())
            {
                long long val=segMaxi.getVal(l+1,r)-segMini.getVal(l+1,r);
                q.push({val,{l+1,r}});
                st.insert({l+1,r});
            }

            if(l<=r-1 && st.find({l,r-1})==st.end())
            {
                long long val=segMaxi.getVal(l,r-1)-segMini.getVal(l,r-1);
                q.push({val,{l,r-1}});
                st.insert({l,r-1});
            }

        }

        return result;

    }
};