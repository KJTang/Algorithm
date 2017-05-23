// solution: 23ms, 49 cases
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while (i != data.size()) {
            if ((data[i] & 0x80) == 0) {    // 1-byte: start with 0
                ++i;
            } else {                        // n-byte: start with 11
                if ((data[i] & 0x40) != 0) {// invalid: start with 10
                    return false;
                }
                int cur = data[i++];
                int bit = 0x40;
                while ((cur & bit) != 0) {
                    if (bit == 0x08 || i == data.size() || !(data[i] & 0x80) || (data[i] & 0x40)) {
                        return false;
                    }
                    bit >>= 1;
                    ++i;
                }
            }
        }
        return true;
    }
};
