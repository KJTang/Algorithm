// solution1: 12ms, 54 cases
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long result = 1;
        for (int i = 0; i != b.size(); ++i) {
            std::cout << "result: " << result << std::endl;
            result = PowWithMod(result, 10);
            result *= PowWithMod(a, b[i]);
            result %= k;
        }
        return result;
    }
private:
    const int k = 1337;

    int PowWithMod(int a, int b) {
        if (b == 0) { return 1; }
        if (b == 1) { return a; }
        int half = PowWithMod(a, b / 2);
        return (half * half % k) * (b % 2 ? a : 1) % k;
    }
};

// solution2: 13ms, 54 cases
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long result = 1;
        a %= k;
        for (int i = 0; i != b.size(); ++i) {
            // use pow(pow(res, 5), 2) to instead pow(res, 10) in case 1337 ^ 10 is to large to save in 'long long'
            result = (long long)std::pow(((long long)std::pow(result, 5) % k), 2) % k;     
            // use code below to instead pow(a, b[i]) in case a is to large
            while (b[i]) {
                result *= a;
                result %= k;
                --b[i];
            }
        }
        return result;
    }
private:
    const int k = 1337;
};