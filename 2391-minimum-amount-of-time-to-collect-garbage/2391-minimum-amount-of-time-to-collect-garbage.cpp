class Solution {
public:
    int garbageCollection(vector<string>& str, vector<int>& travel) {
        int ans = 0;
        int maxG = 0,maxP = 0,maxM = 0;
        travel.emplace(travel.begin(),0);
        for(int i = 1;i<travel.size();i++) travel[i] += travel[i - 1];
        int n = str.size();
        for(int i = 0;i<n;i++){
            int g = 0,p = 0,m = 0;
            for(char &c:str[i]){
                if(c == 'G') g++;
                else if(c == 'P') p++;
                else m++;
            }
            if(g) maxG = i;
            if(p) maxP = i;
            if(m) maxM = i;
            ans += g + p + m;
        }
        
        return ans + travel[maxG] + travel[maxP] + travel[maxM];
    }
};
