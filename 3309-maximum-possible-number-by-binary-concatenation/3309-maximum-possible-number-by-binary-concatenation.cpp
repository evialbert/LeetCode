class Solution {
public:
    void permutation(int index,vector<int>& nums,vector<vector<int>>& result){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permutation(index+1,nums,result);
            swap(nums[i],nums[index]);
        }
    }
    string removeLeadingZeros(string& s){
        size_t start = s.find_first_not_of('0');
        if(start==string::npos)
            return "0";
        return s.substr(start);
    }
    string binaryConversion(vector<int>& arr){
        string res = "";
        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            int digit;
            string val = "";
            while(num){
                digit = num%2;
                val += to_string(digit);
                num /= 2;
            }
            reverse(val.begin(),val.end());
            res += removeLeadingZeros(val);
        }
        return res;
    }
    int maxGoodNumber(vector<int>& nums) {
        string bin = "";
        vector<vector<int>> permute;
        vector<int> combine = nums;
        permutation(0,combine,permute);
        int i,j;
        int answer = 0;
        for(i=0;i<permute.size();i++){
            bin += binaryConversion(permute[i]);
            answer = max(answer,stoi(bin,nullptr,2));
            bin = "";
        }
        return answer;
    }
};