class Solution {
public:
    char after(char ch) {
        vector < char >nxt= {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                          'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                          't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'};
        return nxt[ch-'a'];
    }
    int minOperations(string s) {
        int n = s.length();
        int count = 0;
        //sort(s.begin(),s.end());
        unordered_map<char, int> mpp;
        for (char c : s) {
            if(c=='a'){
                continue;
            }
            mpp[c]++;
        }
        string temp="";
        for (auto it : mpp) {
            temp+=it.first;
        }
        sort(temp.begin(),temp.end());
        int t=temp.size();
        if(t==1){
            return (26-temp[0]+'a');
        }
        for(int i=1;i<t;i++){
            if(i==t-1){
                count+=(26-temp[i]+'a');
            }
            count+=((temp[i]-temp[i-1]));
            
        }
        return count;
    }
};