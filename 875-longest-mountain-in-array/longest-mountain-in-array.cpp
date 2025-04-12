class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n=a.size();
        int i=0,start=0,top=-1,len=0;
        while(i<n-1)
        {
            while(i<n-1 and a[i]>=a[i+1]) i++,start++;  //checking where the hill starts
            if(i==n-1) break;   //if hill doesn't start eg. 2 2 2
            while(i<n-1 and a[i]<a[i+1]) i++,top=i; //incrementing untill we find a hill top
            while(i<n-1 and a[i]>a[i+1]) i++;   //going downhill after finding a top
            if(top<i) len = max(len,i-start+1); //checking if a value exists after hill top
            start=i;    //staring from this position for the next hill
        }
        return len;
    }
};