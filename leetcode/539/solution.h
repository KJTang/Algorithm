// solution: 16ms
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // get minutes
        std::vector<int> minutes(timePoints.size());
        for (int i = 0; i != timePoints.size(); ++i) {
            minutes[i] = GetMinutes(timePoints[i]);
        }
        // sort
        std::sort(minutes.begin(), minutes.end());
        // find minimum
        int min = minutes.back() - minutes.front();
        // compute by opposite order (example: 23:59 - 00:00)
        if (min > 720) {
            min = 1440 - min;
        }
        for (int i = 1; i != minutes.size() && min != 0; ++i) {
            int diff = minutes[i] - minutes[i - 1];
            if (diff < min) {
                min = diff;
            }
        }
        return min;
    }
private:
    int GetMinutes(const std::string& time) {
        int hours = 0, mins = 0;
        int i = 0;
        while (isdigit(time[i])) {
            hours *= 10;
            hours += time[i] - '0';
            ++i;
        }
        ++i;    // eat ':'
        while (isdigit(time[i])) {
            mins *= 10;
            mins += time[i] - '0';
            ++i;
        }
        return hours * 60 + mins;
    }
};