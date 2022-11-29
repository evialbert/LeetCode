// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
   
    int start=0, end=n;
       
    while(end-start>1)
    {
        int mid=(end-start)/2+start;
        
        if(isBadVersion(mid))  
            end=mid;
        else  
            start=mid;
    }
    return end;
}
};