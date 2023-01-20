class Solution {
public:
    string smallestNumber(string pat) {
        string ans;
        for(int i = 0; i <= pat.length();i++){
            ans += to_string(i+1);
        }
        for(int i = 0; i < pat.length();){
            if(pat[i]=='D'){
                int temp = i;
                int count = 0;
                while(i < pat.length()&&pat[i]==pat[temp]){
                    i++;
                    count++;
                }
                int x = temp;
                int y = temp + count;
                while(x < y){
                    swap(ans[x++],ans[y--]);
                }
            }
            else{
                i++;
            }
        }
        return ans;
    }
};