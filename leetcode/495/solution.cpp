class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() <= 0) {
            return 0;
        } else if (timeSeries.size() == 1) {
            return duration;
        } else {
            int result = duration;
            int temp = 0;
            for (int i = 1; i != timeSeries.size(); ++i) {
                temp = timeSeries[i] - timeSeries[i-1];
                result += temp < duration ? temp : duration;
            }
            return result;
        }
    }
};
