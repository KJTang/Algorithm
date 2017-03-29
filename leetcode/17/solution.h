// solution: 0ms
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || !RecursiveFunc(digits, 0)) {
            return {};
        }
        return result;
    }
private:
    std::vector<std::string> result;
    std::string str;
    std::map<char, std::string> digits_map = { 
        {'2', "abc"}, 
        {'3', "def"}, 
        {'4', "ghi"}, 
        {'5', "jkl"}, 
        {'6', "mno"}, 
        {'7', "pqrs"}, 
        {'8', "tuv"}, 
        {'9', "wxyz"}, 
    };

    bool RecursiveFunc(const std::string& digits, int cur) {
        if (cur == digits.size()) {
            result.push_back(str);
            return true;
        }
        std::string letters = digits_map[digits[cur]];
        if (!letters.size()) {
            return false;
        }
        for (int i = 0; i != letters.size(); ++i) {
            str.push_back(letters[i]);
            if (!RecursiveFunc(digits, cur + 1)) {
                return false;
            }
            str.pop_back();
        }
        return true;
    }
};