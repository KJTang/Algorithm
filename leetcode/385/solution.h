/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// solution: 29ms
class Solution {
public:
    NestedInteger deserialize(string s) {
        return Parse(s);
    }
private:
    int i = 0;

    NestedInteger Parse(const std::string& s) {
        if (s[i] == '[') {
            return ParseList(s);
        } else {
            return ParseNum(s);
        }
    }

    NestedInteger ParseNum(const std::string& s) {
        bool sign = true;
        if (s[i] == '-') {
            ++i;
            sign = false;
        }
        int value = 0;
        while (i != s.size() && isdigit(s[i])) {
            value *= 10;
            value += s[i] - '0';
            ++i;
        }
        value *= sign ? 1 : -1;
        return NestedInteger(value);
    }

    NestedInteger ParseList(const std::string& s) {
        NestedInteger cur;
        // empty list: "[]"
        if (s[i + 1] == ']') {
            i += 2;
            return cur;
        }
        // non empty list
        do {
            ++i;    // eat '[' or ','
            NestedInteger child = Parse(s);
            cur.add(child);
        } while (s[i] != ']');
        ++i;        // eat ']'
        return cur;
    }
};