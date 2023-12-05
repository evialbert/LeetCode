class Solution {
	public:
		string breakPalindrome(string pal) {
			int n=pal.size();
			if(n==1) return "";
			for(int i=0;i<n;i++){
				if(pal[i]!='a'){
					char temp=pal[i];
					pal[i]='a';
					set<char>s;
					for(auto i:pal) s.insert(i);
					if(s.size()!=1) return pal;
					pal[i]=temp;
				}   
			}
			pal[n-1]='b';
			return pal;
		}
	};