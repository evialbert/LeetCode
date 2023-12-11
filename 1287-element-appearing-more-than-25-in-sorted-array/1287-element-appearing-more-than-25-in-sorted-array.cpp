class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        int x = len/4, count = 1;
        int p = arr[0];
        for(int i=1;i<len;i++)
        {
            if(p == arr[i])
                count++;
            else
                count = 1;
            if(count>x)
                return arr[i];
            
            p=arr[i];
        }
        return p;
    }
};