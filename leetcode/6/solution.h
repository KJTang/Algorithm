// solution: 29ms

// examples: 
// 3-rows:
// a   e   i   m 
//  b d f h j l n
//   c   g   k
// 5-rows: 
// a       i           0        8
//  b     h j           1      7 9      15
//   c   g   k           2    6   10   14 
//    d f     l n         3  5     11 13
//     e       m           4        12

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int seg = (numRows - 1) * 2;
        std::string result;
        for (int i = 0; i != numRows; ++i) {
            int offset = seg - i * 2;
            for (int j = i; j < s.size(); ) {
                result += s[j];
                j += offset == 0 ? seg - offset : offset;
                offset = seg - offset;
            }
        }
        return result;
    }
};
