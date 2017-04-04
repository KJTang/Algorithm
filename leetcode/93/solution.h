// solution: 3ms
#include <stringstream>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        DFS(s, 0, 1);
        return result;
    }
private:
    std::stringstream ss;
    std::vector<std::string> result;
    std::vector<int> ip;

    void DFS(const std::string& s, int cur, int count) {
        // boundary
        if (cur == s.size() && count == 5) {
            ss << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
            result.push_back(ss.str());
            ss.str("");
            return;
        } else if (cur == s.size() || count == 5) {
            return;
        }
        // DFS
        if (s[cur] == '0') {    // start with '0'
            ip.push_back(0);
            DFS(s, cur + 1, count + 1);
            ip.pop_back();
        } else {                // start with others
            int num = 0;
            for (int i = cur; i != s.size(); ++i) {
                num *= 10;
                num += s[i] - '0';
                if (num <= 255) {
                    ip.push_back(num);
                    DFS(s, i + 1, count + 1);
                    ip.pop_back();
                } else {
                    return;
                }
            }
        }
    }
};