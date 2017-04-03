// solution: 6ms
class Solution {
public:
    string simplifyPath(string path) {
        path += "/@/";   // end flag
        std::vector<std::string> path_stack;
        int i = 0;
        while (i != path.size()) {
            while (path[i] == '/') {
                ++i;
            }
            std::string cur;
            while (path[i] != '/') {
                cur += path[i];
                ++i;
            }
            if (cur == ".") {           // still in cur dir
                // do nth.
            } else if (cur == "..") {   // last dir
                if (!path_stack.empty()) {
                    path_stack.pop_back();
                }
            } else if (cur == "@") {   // exit
                break;
            } else {
                path_stack.push_back(cur);
            }
        }
        std::string result;
        for (int i = 0; i != path_stack.size(); ++i) {
            result += "/";
            result += path_stack[i];
        }
        return result.empty() ? "/" : result;
    }
};