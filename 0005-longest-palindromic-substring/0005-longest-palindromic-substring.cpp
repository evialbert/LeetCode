class Solution {
public:
    
  string longestPalindrome(string A) { 
    int n = A.size();
    int start, length = 1;
    for(int i=0;i<n-1;i++){
        int l,r;
        // for odd length 
        l=i;r=i;
        while(l>=0 && r<n && A[l] == A[r]){
            if(r-l+1 > length){
            length = r-l+1;
            start = l;
             }
            l--;
            r++;
        }
         // for even length
        l=i; r = i+1;
        while(l>=0 && r<n && A[l] == A[r]){
            if(r-l+1 > length){
            length = r-l+1;
            start = l;
              }
            l--;
            r++;
        }
     }
    
    if(length == 1) return A.substr(0,1);
     return A.substr(start,length); 
    }
};