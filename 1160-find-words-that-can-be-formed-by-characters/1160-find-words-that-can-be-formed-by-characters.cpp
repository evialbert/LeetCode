class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        int count[26]={0};
        int w=words.size(),c=chars.length();
        for(int i=0;i<c;i++){
            count[chars[i]-'a']++;
        }
        for(auto str:words){
            int clone[26];
            copy(count, count + 26, clone);
            bool f=1;
            for(char ch:str){
                if(clone[ch-'a']>0){
                    clone[ch-'a']--;
                }
                else{
                    f=0;
                    continue;
                }
            }
            if(f)
                ans+=str.length();
        }
        return ans;
    }
};