// solution: 6ms, 16 cases
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i != gas.size(); ) {
            int result = CanComplete(i, gas, cost);
            if (result == -1) {
                return i;
            }
            i = result;
        }
        return -1;
    }

private:
    int CanComplete(int start, const std::vector<int>& gas, const std::vector<int>& cost) {
        int gas_cnt = 0;
        int cur = start;

        do {
            gas_cnt += gas[cur] - cost[cur];
            if (++cur == gas.size()) {
                cur = 0;
            }
        } while (gas_cnt >= 0 && cur != start);

        // gas_cnt == -1: can complete
        // gas_cnt != -1: cannot complete, return next start point, if has no start point, just return gas.size()
        return gas_cnt >= 0 ? -1 : (cur <= start ? gas.size() : cur);
    }
};


// solution: 73ms, 16 cases
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i != gas.size(); ++i) {
            if (CanComplete(i, gas, cost)) {
                return i;
            }
        }
        return -1;
    }

private:
    bool CanComplete(int start, const std::vector<int>& gas, const std::vector<int>& cost) {
        int gas_cnt = 0;
        int cur = start;

        do {
            gas_cnt += gas[cur] - cost[cur];
            if (++cur == gas.size()) {
                cur = 0;
            }
        } while (gas_cnt >= 0 && cur != start);

        return gas_cnt >= 0;
    }
};