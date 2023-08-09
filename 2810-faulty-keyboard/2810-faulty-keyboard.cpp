class Solution {
public:
  string finalString(string s) {
	string res;
	for (const char& c : s) {
		if (c == 'i')
			reverse(begin(res), end(res));
		else
			res += c;
	}
	return res;
}
};