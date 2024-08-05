class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<arr.size();i++)
        {
            string t=arr[i];
            m[t]++;
        }
        int val=0;
        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]]==1)
            {
                val++;
                if(val==k)
                    return arr[i];
            }
        }
        return "";
    }
};