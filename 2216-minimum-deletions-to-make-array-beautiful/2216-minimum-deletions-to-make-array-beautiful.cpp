class Solution
{
    public:
        int minDeletion(vector<int> &a)
        {
            int res=0;
            for (int i=0;i<a.size()-1;i++)
                if((i+res)%2==0&&a[i]==a[i+1])res++;
            if((a.size()-res)%2)return ++res;
            return res;
        }
};