// solution: 3ms
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        max_paren = n;
        RecursiveFunc(n * 2);
        return result;
    }
private:
    std::vector<std::string> result;
    std::string cur;
    int paren_left = 0;
    int paren_right = 0;
    int max_paren = 0;

    void RecursiveFunc(int count) {
        if (count <= 0) {
            result.push_back(cur);
            return;
        }
        // '('
        if (paren_left < max_paren) {
            cur.push_back('(');
            ++paren_left;
            RecursiveFunc(count - 1);
            --paren_left;
            cur.pop_back();
        }
        // ')'
        if (paren_left - paren_right > 0) {
            cur.push_back(')');
            ++paren_right;
            RecursiveFunc(count - 1);
            --paren_right;
            cur.pop_back();
        }
    }
};