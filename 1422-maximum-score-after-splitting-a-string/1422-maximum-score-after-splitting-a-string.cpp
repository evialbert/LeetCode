class Solution {
public:
   int maxScore(string s) {
	int max=-1;

	int count_ones=0;
	int count_zeros=0;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='1')
			count_ones++;   
	}

	for(int i=0; i<s.length()-1; i++){
		if(s[i]=='0'){
			count_zeros++;
		}
		else
			count_ones--;
		if(max < count_ones+count_zeros)
		{
			max=count_zeros+count_ones;
		}
	}
	return max;
}
};