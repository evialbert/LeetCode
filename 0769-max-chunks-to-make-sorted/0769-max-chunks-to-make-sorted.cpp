class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count=0,maxmum=0;
      for(int i=0;i<arr.size();i++)
      {
        maxmum=max(maxmum,arr[i]);
        if(maxmum==i)
          count++;
      }return count;
    }
};