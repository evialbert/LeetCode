class Solution {
public:
    int minimumPartition(string s, int k) {
        int res = 0;
        int right = s.size();
        int left = right - 1;
        while(left >= 0){
            string sub = s.substr(left, right - left);
            if(stol(sub) <= k){
                if(left == 0){
                    sub = s.substr(left, right - left);
                    if(stoi(sub) <= k) res++;
                    break;
                }
                left--;
            }
            else{
                left++;
                if(left == right) return -1;
                res++;
                right = left;
                left = right -1;
            }
        }
        return res;
    }
};