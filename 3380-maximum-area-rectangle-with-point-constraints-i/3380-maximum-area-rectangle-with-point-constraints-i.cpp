class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        set<pair<int, int>> pointSet;
        for (const auto& point : points) {
            pointSet.insert({point[0], point[1]});
        }

        int maxArea = 0;
        for (size_t i = 0; i < points.size(); i++) {
            for (size_t j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                // Skip if points share the same x or y coordinate
                if (x1 == x2 || y1 == y2) continue;

                // Check if the other two corners of the rectangle exist
                if (pointSet.count({x1, y2}) && pointSet.count({x2, y1})) {
                    // Verify that no other points lie on the rectangle's border or inside
                    bool valid = true;
                    for (const auto& p : pointSet) {
                        int px = p.first, py = p.second;

                        // Skip the rectangle's corners
                        if ((px == x1 && py == y1) || 
                            (px == x1 && py == y2) || 
                            (px == x2 && py == y1) || 
                            (px == x2 && py == y2)) continue;

                        // Check if the point lies on the border or inside the rectangle
                        if (px > min(x1, x2) && px < max(x1, x2) && 
                            py > min(y1, y2) && py < max(y1, y2)) {
                            valid = false;
                            break;
                        }

                        if ((px == x1 || px == x2) && (py > min(y1, y2) && py < max(y1, y2))) {
                            valid = false;
                            break;
                        }

                        if ((py == y1 || py == y2) && (px > min(x1, x2) && px < max(x1, x2))) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        // Calculate the area of the rectangle
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        // If no rectangle found, return -1
        return maxArea > 0 ? maxArea : -1;
    }
};