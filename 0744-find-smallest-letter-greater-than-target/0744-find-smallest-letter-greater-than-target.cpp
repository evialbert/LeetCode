class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {

		int start=0;
		int end=letters.size()-1;
		int n=letters.size();


		if(target>=letters[end])
			return letters[start];


		while(start<=end)
		{   
			int mid= start+ (end-start)/2;
			int prev=(mid-1+n)%n;
			int next=(mid+1)%n;


			if(letters[mid]==target)
			{
				if(letters[next]!=target)
					return letters[next];
				else
				{
					start=mid+1;
				}
			}
			else if(letters[mid]>target)
			{
				if(target<=letters[prev])
					end=mid-1;
				else
					return letters[mid];
			}
			else
			{
				start=mid+1;
			}

		}

		return letters[0];
	}

};