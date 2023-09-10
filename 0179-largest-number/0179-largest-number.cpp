class Solution {
public:
static bool comp(string& a, string& b)
{
    return a+b>b+a;
}
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> v;
        for(int i:nums)
        v.push_back(to_string(i));
        sort(v.begin(), v.end(), comp);
        string s="";
        for(auto a:v)
        s+=a;
        int i=0;
        while(i<s.size()-1 && s[i]=='0')
        i++;
        return s.substr(i, s.size());
    }
};