class Solution {
public:
    
    bool solve(int x, int y){
        string str1= to_string(x);
        // string str2= to_string(y);
            // cout<< "str1 "<< str1 << " "; 
            // cout<< "str2 " << str2<< endl;
        for(int i=0; i<str1.size(); i++){
            for(int j=i+1; j<str1.size(); j++){
                // cout<< str1[i]<< " "<< str1[j]<<endl;
                swap(str1[i], str1[j]);
                if(stoi(str1)== y) return true;
                swap(str1[i], str1[j]); 
            }
        }
        return false;
    }

    int countPairs(vector<int>& nums) {
        int cnt=0;
        for(int i=0; i< nums.size(); i++){
            for(int j=i+1; j< nums.size(); j++){
                if(nums[i]==nums[j]) cnt++; 
                else if(solve(nums[i], nums[j]) || solve(nums[j], nums[i])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};