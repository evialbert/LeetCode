class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> res;
        int i = 0;
        while(i < a.size()){
            int s = i;
            int j = i + 1;
            while(j < a.size() && a[j] == 1 + a[i]){
                i++;
                j++;
            }
            if(s == i)res.push_back(to_string(a[i]));
            else res.push_back(to_string(a[s]) + "->" + to_string(a[i]));
            i++;
        }
        return res;
    }
};