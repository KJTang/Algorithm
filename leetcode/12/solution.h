// solution: 9ms
class Solution {
public:
    string intToRoman(int num) {
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
private:
    const std::vector<std::string> M = {"", "M", "MM", "MMM"};
    const std::vector<std::string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const std::vector<std::string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const std::vector<std::string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
};