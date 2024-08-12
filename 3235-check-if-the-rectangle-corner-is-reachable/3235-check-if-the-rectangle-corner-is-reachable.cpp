class Solution {
public:
    int rx, ry;
    struct circle {
        long long x, y, r;        
    };
    vector<circle> circle_list;
    int grp[1001];
    int type[1001];    

    bool f_circle_chk(circle &A, circle &B) {
        return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) <= (A.r + B.r) * (A.r + B.r);
    }
    // check for a point in a circle    
    bool f_dot_chk(circle &A, int x, int y) {        
        long long dx = A.x - x;
        long long dy = A.y - y;
        dx *= dx, dy *= dy;
        return dx + dy <= A.r * A.r;
    }
    // check for touching the upper edge
    bool f_chk1(circle &A) {        
        bool ret = f_dot_chk(A, 0, ry)  | f_dot_chk(A, rx, ry) | (f_dot_chk(A, A.x, ry) & (A.x <= rx));        
        return ret;
    }
    // check for touching the right edge
    bool f_chk2(circle &A) {
        bool ret = f_dot_chk(A, rx, ry) | f_dot_chk(A, rx, 0) | (f_dot_chk(A, rx, A.y) & (A.y <= ry));
        return ret;
    }
    // check for touching the bottom edge
    bool f_chk3(circle &A) {
        bool ret = f_dot_chk(A, rx, 0) | f_dot_chk(A, 0, 0) | (f_dot_chk(A, A.x, 0) & (A.x <= rx));        
        return ret;
    }
    // check for touching the left edge
    bool f_chk4(circle &A) {
        bool ret = f_dot_chk(A, 0, 0) | f_dot_chk(A, 0, ry) | (f_dot_chk(A, 0, A.y) & (A.y <= ry));
        return ret;
    }
    // check for a point in a rectangle
    bool f_chk_in(int x, int y) {
        if(x < 0 || y < 0 || x > 2 * rx || y > 2 * ry) return false;
        return true;
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        bool find = false;
        int i, j, n = circles.size(), v;
        rx = X, ry = Y;
        // check a circle touch two valid edges
        for(vector<int> &cur : circles) {
            circle_list.push_back({cur[0], cur[1], cur[2]});
            v = 0;
            if (f_chk1(circle_list.back())) v |= (1 << 0);
            if (f_chk2(circle_list.back())) v |= (1 << 1);
            if (f_chk3(circle_list.back())) v |= (1 << 2);
            if (f_chk4(circle_list.back())) v |= (1 << 3);
            if((v & 3) == 3 || (v & 5) == 5 || (v & 10) == 10 || (v & 12) == 12) return false;
        }

        // find circle groups and check for touching edges
        for (i = 0; i < n; ++i) grp[i] = i;        
        int x, y;
        for (i = 0; i < n; ++i) {
            find = false;
            circle &A  =circle_list[i];
            for (j = 0; j < i; ++j) {
                circle &B = circle_list[j];
                if(f_circle_chk(A, B) && (f_chk_in(A.x + B.x, A.y + B.y) | f_chk_in(A.x * 2, A.y * 2) | f_chk_in(B.x * 2, B.y * 2))) {
                    find = true;
                    int g = min(grp[i], grp[j]);
                    type[g] = type[g] | type[grp[i]] | type[grp[j]];
                    grp[i] = g;
                    grp[j] = g;
                }
            }
            
            if (f_chk1(circle_list[i])) type[grp[i]] |= (1 << 0);
            if (f_chk2(circle_list[i])) type[grp[i]] |= (1 << 1);
            if (f_chk3(circle_list[i])) type[grp[i]] |= (1 << 2);
            if (f_chk4(circle_list[i])) type[grp[i]] |= (1 << 3);
            if((type[grp[i]] & 3) == 3 || (type[grp[i]] & 5) == 5 || (type[grp[i]] & 10) == 10 || (type[grp[i]] & 12) == 12) return false;
        }

        return true;
    }
};