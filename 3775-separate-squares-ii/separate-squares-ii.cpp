class Solution {
private:
    void update(int idx, int l, int r, int ql, int qr, int delta,
                const vector<int>& xs, vector<int>& cnt, vector<long double>& seg) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            cnt[idx] += delta;
        } else {
            int mid = (l + r) / 2;
            update(idx * 2, l, mid, ql, qr, delta, xs, cnt, seg);
            update(idx * 2 + 1, mid, r, ql, qr, delta, xs, cnt, seg);
        }
        if (cnt[idx] > 0) {
            seg[idx] = xs[r] - xs[l];
        } else {
            if (r - l == 1)
                seg[idx] = 0;
            else
                seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        }
    }
    
public:
    double separateSquares(vector<vector<int>>& squares) {
        using ld = long double;
        struct Event {
            ld y;
            int type;
            int x1, x2;
        };
        
        vector<Event> events;
        vector<int> xs;
        
        for (int i = 0; i < squares.size(); i++) {
            int x = squares[i][0], y = squares[i][1], l = squares[i][2];
            int x2 = x + l, y2 = y + l;
            events.push_back({(ld)y, 1, x, x2});
            events.push_back({(ld)y2, -1, x, x2});
            xs.push_back(x);
            xs.push_back(x2);
        }
        
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        
        sort(events.begin(), events.end(), [](const Event &a, const Event &b) {
            return a.y < b.y;
        });
        
        int m = xs.size();
        vector<int> cnt(4 * m, 0);
        vector<ld> seg(4 * m, 0.0L);
        
        ld totalArea = 0.0L;
        ld prev_y = events[0].y;
        vector<tuple<ld, ld, ld>> segments;
        int nEvents = events.size();
        int i = 0;
        while (i < nEvents) {
            ld cur_y = events[i].y;
            if (cur_y > prev_y) {
                ld height = cur_y - prev_y;
                ld unionLength = seg[1];
                segments.push_back({prev_y, cur_y, unionLength});
                totalArea += unionLength * height;
                prev_y = cur_y;
            }
            while (i < nEvents && events[i].y == cur_y) {
                int ql = int(lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin());
                int qr = int(lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin());
                update(1, 0, m, ql, qr, events[i].type, xs, cnt, seg);
                i++;
            }
        }
        
        ld target = totalArea / 2.0L;
        ld cum = 0.0L;
        for (int j = 0; j < segments.size(); j++) {
            ld y_start, y_end, union_len;
            tie(y_start, y_end, union_len) = segments[j];
            ld segArea = union_len * (y_end - y_start);
            if (cum + segArea >= target) {
                if (union_len == 0)
                    return (double)y_start;
                ld remain = target - cum;
                ld delta_y = remain / union_len;
                ld ans = y_start + delta_y;
                return (double)ans;
            }
            cum += segArea;
        }
        
        return (double)prev_y;
    }
};