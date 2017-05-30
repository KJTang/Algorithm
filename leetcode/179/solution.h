// solution: 6ms, 221 cases
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        std::sort(nums.begin(), nums.end(), [](long long a, long long b) {
            if (!a) { return false; }
            if (!b) { return true; }
            long long ab = a, ba = b;
            long long tmp = b;
            long long factor = 1;
            // ab
            while (tmp) {
                factor *= 10;
                tmp /= 10;
            }
            ab = ab * factor + b;
            // ba
            tmp = a;
            factor = 1;
            while (tmp) {
                factor *= 10;
                tmp /= 10;
            }
            ba = ba * factor + a;
            return ab > ba;
        });

        if (nums[0] == 0) {
            return "0";
        } else {
            std::string result;
            for (int i = 0; i != nums.size(); ++i) {
                result += std::to_string(nums[i]);
            }
            return result;
        }
    }
};


// solution: 13ms, 221 cases
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }

        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            if (!a) { return false; }
            if (!b) { return true; }
            std::string str_a = std::to_string(a);
            std::string str_b = std::to_string(b);
            std::string str_ab = str_a + str_b;
            std::string str_ba = str_b + str_a;
            for (int i = 0; i != str_ab.size(); ++i) {
                if (str_ab[i] > str_ba[i]) {
                    return true;
                } else if (str_ba[i] > str_ab[i]) {
                    return false;
                }
            }
            return true;
        });

        if (nums[0] == 0) {
            return "0";
        } else {
            std::string result;
            for (int i = 0; i != nums.size(); ++i) {
                result += std::to_string(nums[i]);
            }
            return result;
        }
    }
};