// solution: 3ms
class Solution {
public:
    string validIPAddress(string IP) {
        for (int i = 0; i != 5; ++i) {
            if (IP[i] == '.') {
                return ValidIPv4(IP) ? "IPv4" : "Neither";
            } else if (IP[i] == ':') {
                return ValidIPv6(IP) ? "IPv6" : "Neither";
            }
        }
        return "Neither";
    }
private:
    bool ValidIPv4(std::string& IP) {
        IP.push_back('.');          // add ending
        int count = 0;
        for (int i = 0; i != IP.size(); ++i, ++count) {
            if (IP[i] == '.' || (IP[i] == '0' && IP[i + 1] != '.')) {   // has empty segment or leading '0' is invalid
                return false;
            }
            int num = 0;
            while (IP[i] != '.') {
                num *= 10;
                num += IP[i] - '0';
                if (!isdigit(IP[i]) || num >= 256) {
                    return false;
                }
                ++i;
            }
        }
        IP.pop_back();              // remove ending
        return count == 4;
    }

    bool ValidIPv6(std::string& IP) {
        IP.push_back(':');          // add ending
        int count = 0;
        for (int i = 0; i != IP.size(); ++i, ++count) {
            if (IP[i] == ':') {     // has empty segment is invalid
                return false;
            }
            for (int j = 0; j != 4 && IP[i] != ':'; ++i, ++j) {
                if (!(isdigit(IP[i]) || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F'))) {
                    return false;
                }
            }
            if (IP[i] != ':') {
                return false;
            }
        }
        IP.pop_back();              // remove ending
        return count == 8;
    }
};