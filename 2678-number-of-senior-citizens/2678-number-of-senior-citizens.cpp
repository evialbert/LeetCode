class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        vector<int>age;
        for(int i=0;i<n;i++){
            string given=details[i];
            char char11=given.at(11);
            char char12=given.at(12);
            
            int dec=char11-'0';
            int uni=char12-'0';
            int num=(dec*10)+uni;
            age.push_back(num);
        }
        int cnt=0;
        for(int i=0;i<age.size();i++){
            if(age[i]>60){
                cnt++;
            }
        }
        return cnt;
    }
    };