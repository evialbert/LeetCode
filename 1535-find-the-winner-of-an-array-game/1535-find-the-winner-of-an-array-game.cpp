class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        int i1 = 0;
        int i2 = 1;
        int n = arr.size();
        int cnt = 0;
        while(i2<n && cnt<k)
        {
            if(arr[i1]<arr[i2]){i1=i2;cnt=1;}
            else{cnt++;}
            i2++;
        }
        return arr[i1];
    }
};

//Time complexity: O(n)
//Space complexity: O(1)