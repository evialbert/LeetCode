class Solution {
public:
	vector<string>v;
	void solve(int i,int n,string& s){
		if(i>=n){
			v.push_back(s);
			return;
		}
		s.push_back('1');
		solve(i+1,n,s);
		s.pop_back();
		s.push_back('0');
		solve(i+1,n,s);
		s.pop_back();
	}

	string findDifferentBinaryString(vector<string>& nums) {
		int n=nums.size();
		string s="";
		solve(0,n,s);
		for(auto i:v){
			if(nums.end()==find(nums.begin(),nums.end(),i))return i; 
		}
		return "";
	}
};