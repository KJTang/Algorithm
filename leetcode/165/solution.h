// solution: 0ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0, num2 = 0;
        int p1 = 0, p2 = 0;
        while (true) {
            // get version num
            num1 = 0, num2 = 0;
            while (p1 != version1.size() && version1[p1] != '.') {
                num1 *= 10;
                num1 += version1[p1] - '0';
                ++p1;
            }
            while (p2 != version2.size() && version2[p2] != '.') {
                num2 *= 10;
                num2 += version2[p2] - '0';
                ++p2;
            }
            // compare
            if (p1 == version1.size() && p2 == version2.size()) {
                if (num1 == num2) {
                    return 0;
                } else {
                    return (num1 > num2 ? 1 : -1);
                }
            }
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            } else {    // eat '.'
                if (p1 != version1.size()) {
                    ++p1;
                }
                if (p2 != version2.size()) {
                    ++p2;
                }
            }
        }
        return 0;
    }
};
