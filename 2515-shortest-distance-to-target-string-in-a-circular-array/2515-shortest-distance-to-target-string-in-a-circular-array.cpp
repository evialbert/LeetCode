class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
         int ind= find(words.begin(),words.end(),target)-words.begin();
        int n= words.size();
        if (ind==n)return -1;
        if (words[startIndex]==target) return 0;
        int i= startIndex-1;
        int j= startIndex+1;
        int cnt1=0; int cnt2=0;
        while (true){
            cnt1++; cnt2++;
            if ((i>=0 && words[i%n]==target) || words[(n+i)%n]==target){
                return cnt1;
            }
            if ((j<n && words[j%n]==target) || words[(n+j)%n]==target){
                return cnt2;
            }
            i--; j++;
        }
        
        return -1;
    }
};