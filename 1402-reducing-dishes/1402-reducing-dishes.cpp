class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        int n=s.size();
        int total=0;
        int start=n-1;
        for(int i=n-1;i>=0;i--){
            total+=s[i];
            if(total<0)
                break;
            start--;
        }
        start++;
        total=0;
        int k=1;
        for(int i=start;i<n;i++){
            total+=((k++)*s[i]);
        }
        return total;
    }
};