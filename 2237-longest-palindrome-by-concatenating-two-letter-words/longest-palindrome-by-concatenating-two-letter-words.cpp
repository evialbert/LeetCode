class Solution {
public:
    string reverse(string temp){
        string temp2="";
        temp2+= temp[1];
        temp2+=temp[0];
        return temp2;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>rec;
        for(auto itr : words){
            rec[itr]++;
        }
        int max_equals =0;
        int ans =0;
        bool ifOdd = false;
        for(auto &itr : rec){
            // check if same
            if(itr.first[0] == itr.first[1]){
                max_equals +=  (((int)itr.second)/2)*2;
                if(itr.second%2){
                    ifOdd|= true;
                }
            }
            // find the reverse
            else{
                auto temp = rec.find(reverse(itr.first));
                if(temp != rec.end()){
                    ans += min(itr.second,temp->second)*4;
                    rec[itr.first] = 0;
                }
            }
        }
        cout<<max_equals<<endl;
        ans+=max_equals*2;
        if(ifOdd){
            ans+=2;
        }
        return ans;

        
    }
};