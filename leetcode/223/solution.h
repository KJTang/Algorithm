// solution1: 15ms, 3081 cases
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rect1_area = (C - A) * (D - B);
        int rect2_area = (G - E) * (H - F);
        int cross_area = 0;
        // x
        int x_left = std::max(A, E);
        int x_right = std::min(C, G);
        // y
        int y_down = std::max(B, F);
        int y_up = std::min(D, H);
        if (x_right > x_left && y_up > y_down) {
            cross_area = (x_right - x_left) * (y_up - y_down);
        }
        return rect1_area + rect2_area - cross_area;
    }
};

// solution2: 29ms, 3081 cases
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int rect1_area = (C - A) * (D - B);
        int rect2_area = (G - E) * (H - F);
        // x
        int x_left = std::max(A, E);
        int x_right = std::min(C, G);
        int x_offset = x_left < x_right ? x_right - x_left : 0;
        // y
        int y_down = std::max(B, F);
        int y_up = std::min(D, H);
        int y_offset = y_down < y_up ? y_up - y_down : 0;
        int cross_area = x_offset * y_offset;
        return rect1_area + rect2_area - cross_area;
    }
};