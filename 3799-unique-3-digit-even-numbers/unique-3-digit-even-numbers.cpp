class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        sort(digits.begin(),digits.end());
        int count = 0;
        for(int i=0;i<n;i++){
            if(digits[i]==0 || (i>0 && digits[i]==digits[i-1])){
                continue;
            }
            for(int j=0;j<n;j++){
                if(j==i || (j>0 && i!=j-1 && digits[j-1]==digits[j])){
                    continue;
                }
                for(int k=0;k<n;k++){
                    if(k==i || k==j || (k>0 && i!=k-1 && j!=k-1 && digits[k-1]==digits[k])){
                        continue;
                    }
                    if(digits[k]%2==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};