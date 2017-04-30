// solution1: 22ms, 24 cases
// zero:   z
// one:    o - zero - two - four
// two:    w
// three:  h - eight
// four:   r - zero - three   
// five:   f - four
// six:    x
// seven:  v - five
// eight:  g
// nine:   i - five - six - eight
class Solution {
public:
    string originalDigits(string s) {
        std::vector<unsigned int> letters(26, 0);
        std::vector<unsigned int> digits(10, 0);
        // count all letters
        for (int i = 0; i != s.size(); ++i) {
            letters[s[i] - 'a'] += 1;
        }
        // zero, two, six, eight
        digits[0] = letters['z' - 'a'];        
        digits[2] = letters['w' - 'a'];        
        digits[6] = letters['x' - 'a'];        
        digits[8] = letters['g' - 'a'];        
        // three, four, five, seven
        digits[3] = letters['h' - 'a'] - digits[8];        
        digits[4] = letters['r' - 'a'] - digits[0] - digits[3];        
        digits[5] = letters['f' - 'a'] - digits[4];        
        digits[7] = letters['v' - 'a'] - digits[5];        
        // one, nine
        digits[1] = letters['o' - 'a'] - digits[0] - digits[2] - digits[4];        
        digits[9] = letters['i' - 'a'] - digits[5] - digits[6] - digits[8];

        std::string result;
        for (int i = 0; i != digits.size(); ++i) {
            result.append(digits[i], (char)(i + '0'));
        }
        return result;
    }
};

// solution2: DFS: tle
class Solution {
public:
    string originalDigits(string s) {
        counter = s.size();
        // init
        for (int i = 0; i != 26; ++i) {
            letters[i] = 0;
        }
        // input
        for (int i = 0; i != s.size(); ++i) {
            letters[s[i] - 'a'] += 1;
        }
        // DFS
        bool result = false;
        for (int i = 0; i != 10; ++i) {
            if (result = DFS(i)) {
                return str;
            }
        }
        return "";
    }
private:
    int letters[26];
    int counter = 0;
    std::vector<std::string> digits = {
        "zero", "one", "two", "three", "four", 
        "five", "six", "seven", "eight", "nine"
    };

    std::string str;

    bool DFS(int letter) {
        // remove
        for (auto it = digits[letter].begin(); it != digits[letter].end(); ++it) {
            letters[*it - 'a'] -= 1;
        }
        // check
        bool succ = true;   // all letters use up
        bool fail = false;  // cannot combine current digit
        for (int i = 0; i != 26; ++i) {
            if (letters[i] < 0) {
                fail = true;
            } else if (letters[i] > 0) {
                succ = false;
            }
        }
        str.push_back(letter + '0');
        // DFS
        if (!succ && !fail) {
            for (int i = letter; i != 10; ++i) {
                if (DFS(i)) {
                    return true;
                }
            }
        }
        // move back
        for (auto it = digits[letter].begin(); it != digits[letter].end(); ++it) {
            letters[*it - 'a'] += 1;
        }
        // result
        if (succ) { 
            return true;
        }
        str.pop_back();
        return false;
    }
};
