class CountIntervals {
public:
	set<pair<int,int>>s;
	int cnt = 0;
	CountIntervals() {

	}

	void add(int left, int right) {
		auto it = s.upper_bound({left,-1});
		if(it!=begin(s) and (--it)->second<left) ++it;

		while(it!=end(s) and it->first<=right){
			left = min(left,it->first);
			right = max(right,it->second);
			cnt-=(it->second-it->first)+1;
			it = s.erase(it);
		}
		cnt+=(right-left+1);
		s.insert({left,right});
	}

	int count() {
		return cnt;
	}
};
/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */