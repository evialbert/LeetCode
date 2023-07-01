class Solution {
private:
	static inline double Sqr(double val) {
		return val * val;
	}

	static inline double Sqr_Distance(double x1, double y1, double x2, double y2) {
		return Sqr(x2 - x1) + Sqr(y2 - y1);
	}
public:
	int numPoints(vector<vector<int>>& darts, int r) {
		double Sqr_R = Sqr(r);

		size_t max = 1;
		for (size_t i = 0; i != darts.size(); ++i) {
			auto& i_pos = darts[i];
			double x0 = i_pos[0];
			double y0 = i_pos[1];
			for (size_t j = i + 1; j != darts.size(); ++j) {
				auto& j_pos = darts[j];
				double x = j_pos[0];
				double y = j_pos[1];
				auto sqr_dist = Sqr_Distance(x0, y0, x, y);
				if (sqr_dist > Sqr_R * 4) continue;

				auto dx = x - x0;
				auto dy = y - y0;
				auto dist = sqrt(sqr_dist);
				auto h = sqrt(Sqr_R - Sqr(dist / 2));
				auto hdx_d = h * dx / dist;
				auto hdy_d = h * dy / dist;

				auto xC1 = x0 + dx / 2 + hdy_d;
				auto xC2 = x0 + dx / 2 - hdy_d;
				auto yC1 = y0 + dy / 2 - hdx_d;
				auto yC2 = y0 + dy / 2 + hdx_d;

				size_t count1 = 0;
				size_t count2 = 0;
				for (auto& pos : darts) {
					x = pos[0];
					y = pos[1];
					#define EPS 1e-6
					if ((Sqr_Distance(xC1, yC1, x, y) - EPS) < Sqr_R) ++count1;
					if ((Sqr_Distance(xC2, yC2, x, y) - EPS) < Sqr_R) ++count2;
				}
				if (count1 > max) max = count1;
				if (count2 > max) max = count2;
			}
		}
		return max;
	}
};