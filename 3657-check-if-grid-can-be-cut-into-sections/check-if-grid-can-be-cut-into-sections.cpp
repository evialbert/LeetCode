struct Solution {
  bool intervalCutsOK(uint n, vector<pair<uint,uint>>& intervals) {
    auto it=intervals.begin();  auto it_e=intervals.end();
    sort(it, it_e);
    bool got1=false;
    uint r=it->second;  // right of overlapping intervals
    for (++it; it!=it_e; ++it) {
      if (it->first >= r) { // cut
        if (got1) return true;
        got1=true;
        r=it->second;
      }
      else r=max(r, it->second);  // extend right of overlapping intervals
    }
    return false;
  }

  bool checkValidCuts(uint n, vector<vector<int>>& rects) {
    uint nr=rects.size();
    for (uint i=0; i<2; ++i) {  // 0:horiz, 1:vert
      vector<pair<uint,uint>> intervals;  intervals.reserve(nr);
      for (auto& j:rects) intervals.emplace_back(j[i], j[i+2]);
      if (intervalCutsOK(n, intervals)) return true;
    }
    return false;
  }
};