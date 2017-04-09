// solution: 3ms
struct ComplexNum {
    int x;
    int y;
    ComplexNum(int ix, int iy) : x(ix), y(iy) {} 
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        ComplexNum complex_a = ParseComplexNum(a, 0);
        ComplexNum complex_b = ParseComplexNum(b, 0);
        std::cout << "a: " << complex_a.x << " " << complex_a.y << std::endl;
        std::cout << "b: " << complex_b.x << " " << complex_b.y << std::endl;

        int result_x = complex_a.x * complex_b.x - complex_a.y * complex_b.y;
        int result_y = complex_a.x * complex_b.y + complex_a.y * complex_b.x;
        std::stringstream ss;
        ss << result_x << "+" << result_y << "i";

        return ss.str();
    }
private:
    ComplexNum ParseComplexNum(const std::string& str, int i) {
        bool sign_a = true, sign_b = true;
        int num_a = 0, num_b = 0;
        // number a's sign
        if (str[i] == '-') {
            sign_a = false;
            ++i;
        }
        // parse a
        while (isdigit(str[i])) {
            num_a *= 10;
            num_a += str[i] - '0';
            ++i;
        }
        // eat '+'
        if (str[i] == '+') {
            ++i;
        }
        // number b's sign
        if (str[i] == '-') {
            sign_b = false;
            ++i;
        }
        // parse b
        while (isdigit(str[i])) {
            num_b *= 10;
            num_b += str[i] - '0';
            ++i;
        }
        num_a *= sign_a ? 1 : -1;
        num_b *= sign_b ? 1 : -1;
        return ComplexNum(num_a, num_b);
    }
};